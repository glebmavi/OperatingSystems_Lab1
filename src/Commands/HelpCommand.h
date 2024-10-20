#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H

#include "Command.h"
#include "../Shell.h"

class HelpCommand : public Command {
private:
    const Shell& shell;
public:
    HelpCommand(const Shell& shell_ref);
    void execute(const std::vector<std::string>& args) override;
};

#endif
