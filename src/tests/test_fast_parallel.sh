# has to be run with sudo for perf command

./run_benchmark_parallel.sh factorize_fast/multiple 10 ../../cmake-build-release/factorize 100000000
./run_benchmark_parallel.sh io-lat-write_fast/multiple 10 ../../cmake-build-release/io-lat-write 500
./run_benchmark_parallel.sh combined_fast/multiple 10 ../../cmake-build-release/combined --factorize-iterations 500000 --io-iterations 100