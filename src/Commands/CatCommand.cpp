#include "CatCommand.h"
#include <iostream>
#include <fstream>

void CatCommand::execute(const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cerr << "cat: missing argument" << std::endl;
        return;
    }
    std::ifstream file(args[0]);
    if (!file) {
        std::cerr << "cat: " << args[0] << ": No such file" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        // Remove trailing '\r' if present
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        std::cout << line << std::endl;
    }
}

std::string CatCommand::get_description() const {
    return "display file content";
}
