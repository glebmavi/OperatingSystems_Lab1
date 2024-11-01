#include "CdCommand.h"
#include <iostream>
#include <unistd.h>

void CdCommand::execute(const std::vector<std::string>& args) {
    if (args.empty()) {
        std::cerr << "cd: missing argument" << std::endl;
        return;
    }
    if (chdir(args[0].c_str()) != 0) {
        perror("cd");
    }
}

std::string CdCommand::get_description() const {
    return "change directory";
}