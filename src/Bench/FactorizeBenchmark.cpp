#include "FactorizeBenchmark.h"
#include <iostream>

namespace FactorizeBenchmark {

    void factorize(long long number, bool verbose, bool first) {
        for (long long i = 2; i * i <= number; ++i) {
            while (number % i == 0) {
                if (verbose || first) std::cout << i << " ";
                number /= i;
            }
        }
        if (verbose || first) {
            if (number > 1) std::cout << number;
            std::cout << std::endl;
        }
    }

    void run(int iterations, long long number, bool verbose) {
        bool first = true;
        for (int i = 0; i < iterations; ++i) {
            if (verbose || first) std::cout << "Factorizing " << number << ": ";
            factorize(number, verbose, first);
            first = false;
        }
    }

}
