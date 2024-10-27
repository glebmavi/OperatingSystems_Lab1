#include "IOLatencyWriteBenchmark.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>

namespace IOLatencyWriteBenchmark {

    constexpr size_t BLOCK_SIZE = 512; // Размер блока данных по варианту
    constexpr size_t FILE_SIZE = 1024 * 1024; // Размер файла в байтах

    void run(int iterations, bool verbose) {
        std::vector<char> buffer(BLOCK_SIZE, 'a'); // Буфер для записи данных
        std::vector<double> durations; // To store duration of each iteration

        for (int i = 0; i < iterations; ++i) {
            // Открытие файла для записи
            std::ofstream file("testfile.dat", std::ios::binary | std::ios::trunc);

            if (!file) {
                std::cerr << "Error opening file for IO benchmark!" << std::endl;
                return;
            }

            auto start = std::chrono::high_resolution_clock::now();

            // Запись данных в файл по блокам
            for (size_t written = 0; written < FILE_SIZE; written += BLOCK_SIZE) {
                file.write(buffer.data(), BLOCK_SIZE);
                if (!file) {
                    std::cerr << "Error writing to file during IO benchmark!" << std::endl;
                    return;
                }
            }

            file.flush();
            file.close();

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            durations.push_back(duration.count()); // Store the duration

            if (verbose) std::cout << "IO Iteration " << i + 1
                      << ": Write latency = " << duration.count() << " seconds"
                      << std::endl;
        }

        // Calculating overall statistics
        double avg_duration = std::accumulate(durations.begin(), durations.end(), 0.0) / durations.size();
        double min_duration = *std::min_element(durations.begin(), durations.end());
        double max_duration = *std::max_element(durations.begin(), durations.end());

        // Printing statistics
        std::cout << "\nOverall Statistics:\n";
        std::cout << "Average write latency: " << avg_duration << " seconds\n";
        std::cout << "Minimum write latency: " << min_duration << " seconds\n";
        std::cout << "Maximum write latency: " << max_duration << " seconds\n";
    }

}
