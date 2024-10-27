#include "FactorizeBenchmark.h"
#include <iostream>
#include <thread>

namespace FactorizeBenchmark {

    void factorize(long long number, bool verbose) {
        for (long long i = 2; i * i <= number; ++i) {
            while (number % i == 0) {
                if (verbose) std::cout << i << " ";
                number /= i;
            }
        }
        if (verbose) {
            if (number > 1) std::cout << number;
            std::cout << std::endl;
        }
    }

    void run(int iterations, long long number, bool verbose) {
        for (int i = 0; i < iterations; ++i) {
            if (verbose) std::cout << "Factorizing " << number << ": ";
            std::thread(factorize, number, verbose).join();
        }
    }

}
