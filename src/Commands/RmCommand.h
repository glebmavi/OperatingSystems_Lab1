#ifndef RMCOMMAND_H
#define RMCOMMAND_H

#include "Command.h"

class RmCommand : public Command {
public:
    void execute(const std::vector<std::string>& args) override;
};

#endif
