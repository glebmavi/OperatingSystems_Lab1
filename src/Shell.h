#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "Commands/Command.h"

class Shell {
private:
    std::map<std::string, Command*> commands;
    std::vector<std::string> history;

    std::vector<std::string> split_input(const std::string& input);  // Helper function

public:
    Shell();
    ~Shell();

    void register_command(const std::string& name, Command* command);
    void register_builtin_commands();
    void execute_command(const std::string& input);
    const std::vector<std::string>& get_history() const;
    const std::map<std::string, Command*>& get_commands() const;
};

#endif
