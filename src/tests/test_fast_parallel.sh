./run_benchmark_parallel.sh factorize_fast 10 ../../cmake-build-release-wsl/factorize 500000
./run_benchmark_parallel.sh io-lat-write_fast 10 ../../cmake-build-release-wsl/io-lat-write 5000
./run_benchmark_parallel.sh combined_fast 10 ../../cmake-build-release-wsl/combined --factorize-iterations 50000 --io-iterations 1000