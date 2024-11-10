# has to be run with sudo for perf command

./run_benchmark.sh factorize/single ../../cmake-build-debug/factorize 1000000
./run_benchmark.sh io-lat-write/single ../../cmake-build-debug/io-lat-write 1000
./run_benchmark.sh combined/single ../../cmake-build-debug/combined --factorize-iterations 500000 --io-iterations 500