#!/bin/bash

# run_benchmark_parallel.sh
# Script to run multiple instances of a benchmark in parallel

if [ $# -lt 4 ]; then
    echo "Usage: $0 <output_log_prefix> <num_instances> <benchmark_program> [additional arguments]"
    exit 1
fi

OUTPUT_LOG_PREFIX=$1
NUM_INSTANCES=$2
BENCHMARK_PROGRAM=$3
shift 3

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

echo "Running $NUM_INSTANCES instances of $BENCHMARK_PROGRAM with arguments '$@'"

# Start mpstat to collect CPU usage in background
MPSTAT_LOG="${OUTPUT_LOG_PREFIX}_mpstat.log"
echo "Collecting CPU usage data with mpstat. Output will be saved to $MPSTAT_LOG"
mpstat 1 > "$MPSTAT_LOG" &
MPSTAT_PID=$!

# Initialize an array to store benchmark PIDs
declare -a BENCHMARK_PIDS=()


# Start instances of benchmark in background
for i in $(seq 1 "$NUM_INSTANCES"); do
    "$BENCHMARK_PROGRAM" "$@" &
    PID=$!
    BENCHMARK_PIDS+=("$PID")
done

# Wait for all benchmark instances to finish
for PID in "${BENCHMARK_PIDS[@]}"; do
    wait "$PID"
done

# Kill mpstat process
kill $MPSTAT_PID

echo "All instances have completed."
