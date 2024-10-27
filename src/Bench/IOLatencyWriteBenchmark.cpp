#include "IOLatencyWriteBenchmark.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

namespace IOLatencyWriteBenchmark {

    constexpr size_t BLOCK_SIZE = 512; // Размер блока данных по варианту
    constexpr size_t FILE_SIZE = 1024 * 1024; // Размер файла в байтах

    void run(int iterations) {
        std::vector<char> buffer(BLOCK_SIZE, 'a'); // Буфер для записи данных

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

            std::cout << "IO Iteration " << i + 1
                      << ": Write latency = " << duration.count() << " seconds"
                      << std::endl;
        }
    }

}
