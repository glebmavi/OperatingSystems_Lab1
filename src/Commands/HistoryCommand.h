#ifndef HISTORYCOMMAND_H
#define HISTORYCOMMAND_H

#include "Command.h"
#include "../Shell.h"

class HistoryCommand : public Command {
private:
    const Shell& shell;
public:
    HistoryCommand(const Shell& shell_ref);
    void execute(const std::vector<std::string>& args) override;
};

#endif
