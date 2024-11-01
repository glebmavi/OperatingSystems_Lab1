#include "FactorizeBenchmark.h"
#include <iostream>
#include <string>

void print_usage(const char* program_name) {
    std::cerr << "Usage: " << program_name << " <iterations> [number] [-v]" << std::endl;
}

int main(int argc, char* argv[]) {

    std::cout << "=== Starting " << argv[0] <<" benchmark ===" << std::endl;

    if (argc < 2 || argc > 4) {
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

    long long number = 1234567890123456789LL; // Дефолтное значение
    bool verbose = false;

    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-v") {
            verbose = true;
        } else {
            try {
                number = std::stoll(arg);
                if (number <= 1) {
                    throw std::invalid_argument("Number must be greater than 1");
                }
            } catch (const std::exception& e) {
                std::cerr << "Invalid number value: " << arg << std::endl;
                return 1;
            }
        }
    }

    FactorizeBenchmark::run(iterations, number, verbose);

    return 0;
}
