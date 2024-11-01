#ifndef LSCOMMAND_H
#define LSCOMMAND_H

#include "Command.h"

class LsCommand : public Command {
public:
    void execute(const std::vector<std::string>& args) override;
    std::string get_description() const override;
};

#endif
