./run_benchmark_parallel.sh factorize_fast/multiple 10 ../../cmake-build-release/factorize 50000
./run_benchmark_parallel.sh io-lat-write_fast/multiple 10 ../../cmake-build-release/io-lat-write 500
./run_benchmark_parallel.sh combined_fast/multiple 10 ../../cmake-build-release/combined --factorize-iterations 10000 --io-iterations 100