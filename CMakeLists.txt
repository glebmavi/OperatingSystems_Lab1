cmake_minimum_required(VERSION 3.10)

project(Lab1 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add flags for compilation without optimization
set(CMAKE_CXX_FLAGS_DEBUG "-O0")

# Enable profiling
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# Add source files for Commands and Shell
set(SHELL_SOURCES
        src/Shell.cpp
        src/Shell.h
        src/Commands/Commands.h
        src/Commands/CatCommand.cpp
        src/Commands/CatCommand.h
        src/Commands/CdCommand.cpp
        src/Commands/CdCommand.h
        src/Commands/HelpCommand.cpp
        src/Commands/HelpCommand.h
        src/Commands/HistoryCommand.cpp
        src/Commands/HistoryCommand.h
        src/Commands/LsCommand.cpp
        src/Commands/LsCommand.h
        src/Commands/MkdirCommand.cpp
        src/Commands/MkdirCommand.h
        src/Commands/RmCommand.cpp
        src/Commands/RmCommand.h
        src/Commands/TouchCommand.cpp
        src/Commands/TouchCommand.h
)

# Add executable files
add_executable(Main src/Main.cpp ${SHELL_SOURCES})
add_executable(io-lat-write src/Bench/io-lat-write.cpp)
add_executable(factorize src/Bench/factorize.cpp)