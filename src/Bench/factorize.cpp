#include <iostream>
#include <vector>
#include <thread>

// Функция для факторизации числа
void factorize(long long number) {
    for (long long i = 2; i * i <= number; ++i) {
        while (number % i == 0) {
            std::cout << i << " ";
            number /= i;
        }
    }
    if (number > 1) std::cout << number;
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: ./factorize <iterations> [number]" << std::endl;
        return 1;
    }

    int iterations = std::stoi(argv[1]);
    long long number = (argc > 3) ? std::stoll(argv[2]) : 1234567890123456789LL;  // Используем аргумент или значение по умолчанию

    // Выполнение факторизации указанное количество раз
    for (int i = 0; i < iterations; ++i) {
        std::cout << "Factorizing " << number << ": ";
        std::thread(factorize, number).join();  // Используем поток для каждой задачи факторизации
    }

    return 0;
}