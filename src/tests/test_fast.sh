# has to be run with sudo for perf command

./run_benchmark.sh factorize_fast/single ../../cmake-build-release/factorize 100000000
./run_benchmark.sh io-lat-write_fast/single ../../cmake-build-release/io-lat-write 1000
./run_benchmark.sh combined_fast/single ../../cmake-build-release/combined --factorize-iterations 500000 --io-iterations 500