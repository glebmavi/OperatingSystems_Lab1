#include "MkdirCommand.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void MkdirCommand::execute(const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cerr << "mkdir: missing argument" << std::endl;
        return;
    }
    if (fs::create_directory(args[0])) {
        std::cout << "Directory created: " << args[0] << std::endl;
    } else {
        std::cerr << "mkdir: failed to create directory " << args[0] << std::endl;
    }
}

std::string MkdirCommand::get_description() const {
    return "create a directory";
}