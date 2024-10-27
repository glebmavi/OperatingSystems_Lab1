#!/bin/bash

# run_benchmark.sh
# Script to run benchmark and collect metrics

if [ $# -lt 3 ]; then
    echo "Usage: $0 <output_log_file> <benchmark_program> [additional_arguments...]"
    exit 1
fi

OUTPUT_LOG=$1
BENCHMARK_PROGRAM=$2
shift 2

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

# Run the benchmark with perf stat and redirect output to log file
echo "Running $BENCHMARK_PROGRAM with arguments '$@'"
echo "Collecting performance metrics with perf stat"
echo "Output will be saved to $OUTPUT_LOG"

# Run perf stat on the benchmark program with specified iterations and any additional arguments
perf stat -d -d -d "$BENCHMARK_PROGRAM" "$@" 2>&1 | tee "$OUTPUT_LOG"
