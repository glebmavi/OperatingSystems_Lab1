#ifndef CATCOMMAND_H
#define CATCOMMAND_H

#include "Command.h"

class CatCommand : public Command {
public:
    void execute(const std::vector<std::string>& args) override;
};

#endif