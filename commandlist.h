#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include <stdlib.h>
#include <vector>
#include "command.h"
#include "inputstate.h"

class Command;

class CommandList {
    private:
    std::vector<Command*> normalCommands;
    std::vector<Command*> SACommands;

    void fillNormalCommands();
    void fillSACommands();

    public:
    CommandList();
    ~CommandList();
    std::vector<Command*>& selectVector(InputState); 
};


#endif

