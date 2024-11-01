#ifndef LAB1_COMMAND_H
#define LAB1_COMMAND_H

#include <vector>
#include <string>

class Command {
public:
    virtual void execute(const std::vector<std::string>& args) = 0;
    virtual std::string get_description() const = 0;
    virtual ~Command() = default;
};


#endif
