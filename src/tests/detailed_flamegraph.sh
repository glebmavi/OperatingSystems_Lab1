#!/bin/bash

# With sudo for perf command

if [ $# -lt 3 ]; then
    echo "Usage: $0 <output_log_directory> <benchmark_program> [additional_arguments...]"
    exit 1
fi

OUTPUT_DIR=$1
BENCHMARK_PROGRAM=$2
shift 2

echo "Generating FlameGraph..."
perf record -F 4096 -g "$BENCHMARK_PROGRAM" "$@"
perf script | "/home/glebmavi/FlameGraph/stackcollapse-perf.pl" > "$OUTPUT_DIR/perf-folded.out"
/home/glebmavi/FlameGraph/flamegraph.pl "$OUTPUT_DIR/perf-folded.out" > "$OUTPUT_DIR/flamegraph_detailed.svg"

rm -f perf.data "$OUTPUT_DIR/perf-folded.out"

