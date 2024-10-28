./run_benchmark.sh factorize.log ../../cmake-build-debug-wsl/factorize 500000
./run_benchmark.sh io-lat-write.log ../../cmake-build-debug-wsl/io-lat-write 10000
./run_benchmark.sh combined.log ../../cmake-build-debug-wsl/combined --factorize-iterations 50000 --io-iterations 10000