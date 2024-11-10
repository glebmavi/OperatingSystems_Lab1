#!/bin/bash

# Script to run benchmark and collect metrics

if [ $# -lt 3 ]; then
    echo "Usage: $0 <output_log_directory> <benchmark_program> [additional_arguments...]"
    exit 1
fi

OUTPUT_DIR=$1
BENCHMARK_PROGRAM=$2
shift 2

# Create the output directory if it doesn't exist
mkdir -p "$OUTPUT_DIR"

# Check if benchmark program exists
if [ ! -f "$BENCHMARK_PROGRAM" ]; then
    echo "Error: Benchmark program $BENCHMARK_PROGRAM not found."
    exit 1
fi

# Check if benchmark program is executable
if [ ! -x "$BENCHMARK_PROGRAM" ]; then
    echo "Error: Benchmark program $BENCHMARK_PROGRAM is not executable."
    exit 1
fi

USER=glebmavi  # Change this to your username

echo "Running $BENCHMARK_PROGRAM with arguments '$@'"
echo "Collecting performance metrics with perf stat, ltrace, strace, top, and FlameGraph"
echo "Output will be saved in $OUTPUT_DIR directory"

# Run perf stat and save output to output_log/perf.log
echo "Running perf stat..."
perf stat -d -d -d "$BENCHMARK_PROGRAM" "$@" 2>&1 | tee "$OUTPUT_DIR/perf.log"

# Run ltrace and save output to output_log/ltrace.log
echo "Running ltrace..."
ltrace -c "$BENCHMARK_PROGRAM" "$@" 2>&1 | tee "$OUTPUT_DIR/ltrace.log"

# Run strace and save output to output_log/strace.log
echo "Running strace..."
strace -c "$BENCHMARK_PROGRAM" "$@" 2>&1 | tee "$OUTPUT_DIR/strace.log"

# Run top for the specified user and save output to output_log/top.log
echo "Running top..."
"$BENCHMARK_PROGRAM" "$@" &  # Run in background
PID=$!
top -b -n3 > "$OUTPUT_DIR/top.log"
wait $PID                     # Wait for the benchmark to complete

# Define paths to FlameGraph scripts
FLAMEGRAPH_SCRIPT="/home/$USER/FlameGraph/flamegraph.pl"
FLAMEGRAPH_COLLAPSE="/home/$USER/FlameGraph/stackcollapse-perf.pl"

# Generate FlameGraph
echo "Generating FlameGraph..."
perf record -F 2048 -g "$BENCHMARK_PROGRAM" "$@"
perf script | "$FLAMEGRAPH_COLLAPSE" > "$OUTPUT_DIR/perf-folded.out"

# Check if flamegraph.pl is available and generate SVG
if command -v "$FLAMEGRAPH_SCRIPT" >/dev/null 2>&1; then
    "$FLAMEGRAPH_SCRIPT" "$OUTPUT_DIR/perf-folded.out" > "$OUTPUT_DIR/flamegraph.svg"
    echo "FlameGraph saved to $OUTPUT_DIR/flamegraph.svg"
else
    echo "FlameGraph script not found."
fi

# Clean up temporary files
rm -f perf.data "$OUTPUT_DIR/perf-folded.out"
