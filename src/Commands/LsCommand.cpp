#include "LsCommand.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void LsCommand::execute(const std::vector<std::string>& args) {
    for (const auto& entry : fs::directory_iterator(".")) {
        std::cout << entry.path().filename().string() << "  ";
    }
    std::cout << std::endl;
}

std::string LsCommand::get_description() const {
    return "list files in the current directory";
}
