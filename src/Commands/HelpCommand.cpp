#include "HelpCommand.h"
#include <iostream>

HelpCommand::HelpCommand(const Shell& shell_ref) : shell(shell_ref) {}

void HelpCommand::execute(const std::vector<std::string>& args) {
    std::cout << "Available commands:" << std::endl;
    std::cout << "ls     - list files in the current directory" << std::endl;
    std::cout << "cd     - change directory" << std::endl;
    std::cout << "touch  - create an empty file" << std::endl;
    std::cout << "cat    - display file content" << std::endl;
    std::cout << "mkdir  - create a directory" << std::endl;
    std::cout << "rm     - remove a file" << std::endl;
    std::cout << "history- show command history" << std::endl;
    std::cout << "exit   - exit the shell" << std::endl;
}
