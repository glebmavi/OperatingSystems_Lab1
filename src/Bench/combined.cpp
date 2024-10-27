#include "FactorizeBenchmark.h"
#include "IOLatencyWriteBenchmark.h"
#include <iostream>
#include <thread>
#include <string>

void print_usage(const char* program_name) {
    std::cerr << "Usage: " << program_name
              << " --factorize-iterations <n> [--number <value>] --io-iterations <m> [-v]" << std::endl;
    std::cerr << "  --factorize-iterations <n> : Number of factorization iterations (required)" << std::endl;
    std::cerr << "  --number <value>           : Number to factorize (optional, default=1234567890123456789)" << std::endl;
    std::cerr << "  --io-iterations <m>        : Number of IO latency write iterations (required)" << std::endl;
    std::cerr << "  -v, --verbose              : Set verbose output" << std::endl;

}

int main(int argc, char* argv[]) {
    int factorize_iterations = 0;
    long long number = 1234567890123456789LL;
    bool verbose = false;
    int io_iterations = 0;

    // Parse arguments
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--factorize-iterations" && i + 1 < argc) {
            factorize_iterations = std::stoi(argv[++i]);
            if (factorize_iterations <= 0) {
                std::cerr << "Error: Factorize iterations must be a positive integer." << std::endl;
                return 1;
            }
        }
        else if (arg == "--number" && i + 1 < argc) {
            number = std::stoll(argv[++i]);
            if (number <= 1) {
                std::cerr << "Error: Number must be greater than 1 for factorization." << std::endl;
                return 1;
            }
        }
        else if (arg == "-v" || arg == "--verbose") {
            verbose = true;
        }
        else if (arg == "--io-iterations" && i + 1 < argc) {
            io_iterations = std::stoi(argv[++i]);
            if (io_iterations <= 0) {
                std::cerr << "Error: IO iterations must be a positive integer." << std::endl;
                return 1;
            }
        }
        else {
            std::cerr << "Unknown or incomplete argument: " << arg << std::endl;
            print_usage(argv[0]);
            return 1;
        }
    }

    if (factorize_iterations == 0 || io_iterations == 0) {
        std::cerr << "Error: Both --factorize-iterations and --io-iterations are required." << std::endl;
        print_usage(argv[0]);
        return 1;
    }

    // Run benchmarks in separate threads
    std::thread factorize_thread([&]() {
        FactorizeBenchmark::run(factorize_iterations, number, verbose);
    });

    std::thread io_thread([&]() {
        IOLatencyWriteBenchmark::run(io_iterations, verbose);
    });

    factorize_thread.join();
    io_thread.join();

    std::cout << "Both benchmarks have completed successfully." << std::endl;

    return 0;
}
