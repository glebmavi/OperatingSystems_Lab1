#include "IOLatencyWriteBenchmark.h"
#include <iostream>
#include <string>

void print_usage(const char* program_name) {
    std::cerr << "Usage: " << program_name << " <iterations> [-v]" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        print_usage(argv[0]);
        return 1;
    }

    int iterations;
    try {
        iterations = std::stoi(argv[1]);
        if (iterations <= 0) {
            throw std::invalid_argument("Iterations must be positive.");
        }
    } catch (const std::exception& e) {
        std::cerr << "Invalid iterations value: " << argv[1] << std::endl;
        return 1;
    }

    bool verbose = false;
    if (argc == 3) {
        std::string arg = argv[2];
        if (arg == "-v") {
            verbose = true;
        } else {
            std::cerr << "Unknown argument: " << arg << std::endl;
            print_usage(argv[0]);
            return 1;
        }
    }

    IOLatencyWriteBenchmark::run(iterations, verbose);

    return 0;
}
