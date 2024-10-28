./run_benchmark.sh factorize_fast.log ../../cmake-build-release-wsl/factorize 500000
./run_benchmark.sh io-lat-write_fast.log ../../cmake-build-release-wsl/io-lat-write 10000
./run_benchmark.sh combined_fast.log ../../cmake-build-release-wsl/combined --factorize-iterations 50000 --io-iterations 10000