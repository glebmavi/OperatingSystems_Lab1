#include "TouchCommand.h"
#include <fstream>
#include <iostream>

void TouchCommand::execute(const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cerr << "touch: missing argument" << std::endl;
        return;
    }
    std::ofstream file(args[0]);
}

std::string TouchCommand::get_description() const {
    return "create an empty file";
}