#include "Shell.h"
#include "Commands/Commands.h"
#include <unistd.h>
#include <algorithm>


Shell::Shell() {
    register_builtin_commands();
}

Shell::~Shell() {
    for (auto& command : commands) {
        delete command.second;
    }
}

void Shell::register_command(const std::string& name, Command* command) {
    commands[name] = command;
}

void Shell::register_builtin_commands() {
    register_command("ls", new LsCommand());
    register_command("cd", new CdCommand());
    register_command("touch", new TouchCommand());
    register_command("cat", new CatCommand());
    register_command("mkdir", new MkdirCommand());
    register_command("rm", new RmCommand());
    register_command("help", new HelpCommand(*this));
    register_command("history", new HistoryCommand(*this));
}

void Shell::execute_command(const std::string& input) {
    std::vector<std::string> args = split_input(input); // Разбиваем строку на токены
    if (args.empty()) return;

    std::string cmd_name = args[0];
    args.erase(args.begin());

    // Встроенные команды
    if (commands.find(cmd_name) != commands.end()) {
        commands[cmd_name]->execute(args);
    }
    // Если команда не встроенная, пытаемся выполнить её как внешнюю программу
    else {
        std::vector<char*> exec_args;
        exec_args.push_back(const_cast<char*>(cmd_name.c_str()));  // Program name
        for (auto& arg : args) {
            exec_args.push_back(const_cast<char*>(arg.c_str()));   // Program arguments
        }
        exec_args.push_back(nullptr);  // Null-terminate the argument list

        // Attempt to execute the external program
        if (execvp(cmd_name.c_str(), exec_args.data()) == -1) {
            std::cerr << "Unknown command or failed to execute: " << cmd_name << std::endl;
        }
    }
}

const std::vector<std::string>& Shell::get_history() const {
    return history;
}

std::vector<std::string> Shell::split_input(const std::string& input) {
    std::vector<std::string> tokens;
    std::string token;
    for (char ch : input) {
        if (isspace(ch)) {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
        } else {
            token.push_back(ch);
        }
    }
    if (!token.empty()) {
        tokens.push_back(token);
    }
    return tokens;
}

const std::map<std::string, Command*>& Shell::get_commands() const {
    return commands;
}

void Shell::add_to_history(const std::string& input) {
    history.push_back(input);
}
