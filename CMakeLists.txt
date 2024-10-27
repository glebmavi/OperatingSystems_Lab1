cmake_minimum_required(VERSION 3.10)

project(Lab1 CXX)

# Установить стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Определение типов сборки, если не задано
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Тип сборки" FORCE)
endif()

# Настройка флагов компиляции для разных типов сборки
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -funroll-loops")

# Добавление исходных файлов для Shell и команд
file(GLOB SHELL_SOURCES
        "src/Shell.cpp"
        "src/Shell.h"
        "src/Commands/*.cpp"
        "src/Commands/*.h"
)

file(GLOB BENCH_SOURCES
        "src/Bench/FactorizeBenchmark.cpp"
        "src/Bench/FactorizeBenchmark.h"
        "src/Bench/IOLatencyWriteBenchmark.cpp"
        "src/Bench/IOLatencyWriteBenchmark.h"
)

# Add executable files
add_executable(Main src/Main.cpp ${SHELL_SOURCES})
add_executable(io-lat-write src/Bench/io-lat-write.cpp ${BENCH_SOURCES})
add_executable(factorize src/Bench/factorize.cpp ${BENCH_SOURCES})
add_executable(combined src/Bench/combined.cpp ${BENCH_SOURCES})