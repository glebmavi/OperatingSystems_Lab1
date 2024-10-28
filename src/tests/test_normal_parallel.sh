./run_benchmark_parallel.sh factorize 10 ../../cmake-build-debug-wsl/factorize 500000
./run_benchmark_parallel.sh io-lat-write 10 ../../cmake-build-debug-wsl/io-lat-write 5000
./run_benchmark_parallel.sh combined 10 ../../cmake-build-debug-wsl/combined --factorize-iterations 50000 --io-iterations 1000