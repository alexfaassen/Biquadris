#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include <stdlib.h>
#include <vector>

class Command;

class CommandList {
    private:
    std::vector<Command*> normalCommands;
    std::vector<Command*> SACommands;

    void fillNormalCommands();
    void fillSACommands();

    public:
    CommandList();
    std::vector<Command*>& selectVector(InputState); 
}


#endif