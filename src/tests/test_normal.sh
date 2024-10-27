./run_benchmark.sh factorize.log ../../cmake-build-debug-wsl/factorize 100000
./run_benchmark.sh io-lat-write.log ../../cmake-build-debug-wsl/io-lat-write 1000
./run_benchmark.sh combined.log ../../cmake-build-debug-wsl/combined --factorize-iterations 10000 --io-iterations 1000