# has to be run with sudo for perf command

./run_benchmark_parallel.sh factorize/multiple 10 ../../cmake-build-debug/factorize 1000000
./run_benchmark_parallel.sh io-lat-write/multiple 10 ../../cmake-build-debug/io-lat-write 500
./run_benchmark_parallel.sh combined/multiple 10 ../../cmake-build-debug/combined --factorize-iterations 500000 --io-iterations 100