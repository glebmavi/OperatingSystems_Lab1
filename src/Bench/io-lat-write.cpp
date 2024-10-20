#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>

#define BLOCK_SIZE 512   // Размер блока данных по варианту
#define FILE_SIZE (1024 * 1024)  // Размер файла в байтах

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./io_lat_write <iterations>" << std::endl;
        return 1;
    }

    int iterations = std::stoi(argv[1]);
    std::vector<char> buffer(BLOCK_SIZE, 'a');  // Буфер для записи данных

    // Проведение итераций
    for (int i = 0; i < iterations; ++i) {
        // Открытие файла для записи
        std::ofstream file("testfile.dat", std::ios::binary | std::ios::trunc);

        if (!file) {
            std::cerr << "Error opening file!" << std::endl;
            return 1;
        }

        // Измерение времени записи
        auto start = std::chrono::high_resolution_clock::now();

        // Запись данных в файл по блокам
        for (size_t written = 0; written < FILE_SIZE; written += BLOCK_SIZE) {
            file.write(buffer.data(), BLOCK_SIZE);
            file.flush();  // Сброс буфера на диск
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Iteration " << i + 1 << ": Write latency = " << duration.count() << " seconds" << std::endl;
    }

    return 0;
}
