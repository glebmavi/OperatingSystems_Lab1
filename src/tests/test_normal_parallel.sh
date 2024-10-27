./run_benchmark_parallel.sh factorize 10 ../../cmake-build-debug-wsl/factorize 100000
./run_benchmark_parallel.sh io-lat-write 10 ../../cmake-build-debug-wsl/io-lat-write 1000
./run_benchmark_parallel.sh combined 10 ../../cmake-build-debug-wsl/combined --factorize-iterations 10000 --io-iterations 1000