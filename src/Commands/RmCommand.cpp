#include "RmCommand.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void RmCommand::execute(const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cerr << "rm: missing argument" << std::endl;
        return;
    }
    if (fs::remove(args[0])) {
        std::cout << "Removed: " << args[0] << std::endl;
    } else {
        std::cerr << "rm: failed to remove " << args[0] << std::endl;
    }
}

std::string RmCommand::get_description() const {
    return "remove a file";
}