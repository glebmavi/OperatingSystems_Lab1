#ifndef MKDIRCOMMAND_H
#define MKDIRCOMMAND_H

#include "Command.h"

class MkdirCommand : public Command {
public:
    void execute(const std::vector<std::string>& args) override;
    std::string get_description() const override;
};

#endif
