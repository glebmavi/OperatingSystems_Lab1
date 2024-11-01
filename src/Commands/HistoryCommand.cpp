#include "HistoryCommand.h"
#include <iostream>

HistoryCommand::HistoryCommand(const Shell& shell_ref) : shell(shell_ref) {}

void HistoryCommand::execute(const std::vector<std::string>& args) {
    const std::vector<std::string>& history = shell.get_history();
    for (size_t i = 0; i < history.size(); ++i) {
        std::cout << i + 1 << ": " << history[i] << std::endl;
    }
}

std::string HistoryCommand::get_description() const {
    return "show command history";
}