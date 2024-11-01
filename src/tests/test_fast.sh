./run_benchmark.sh factorize_fast/single ../../cmake-build-release/factorize 100000
./run_benchmark.sh io-lat-write_fast/single ../../cmake-build-release/io-lat-write 1000
./run_benchmark.sh combined_fast/single ../../cmake-build-release/combined --factorize-iterations 20000 --io-iterations 500