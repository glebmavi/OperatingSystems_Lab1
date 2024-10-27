./run_benchmark.sh factorize_fast.log ../../cmake-build-release-wsl/factorize 100000
./run_benchmark.sh io-lat-write_fast.log ../../cmake-build-release-wsl/io-lat-write 1000
./run_benchmark.sh combined_fast.log ../../cmake-build-release-wsl/combined --factorize-iterations 10000 --io-iterations 1000