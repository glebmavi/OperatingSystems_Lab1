#include "HelpCommand.h"
#include <iostream>

HelpCommand::HelpCommand(const Shell& shell_ref) : shell(shell_ref) {}

void HelpCommand::execute(const std::vector<std::string>& args) {
    std::cout << "Available commands:" << std::endl;
    const auto& commands = shell.get_commands();
    for (const auto& pair : commands) {
        std::cout << pair.first << " - " << pair.second->get_description() << std::endl;
    }
}

std::string HelpCommand::get_description() const {
    return "display this help message";
}
