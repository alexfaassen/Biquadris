#include "commandlist.h"
//include the .h of all of the command subclasses too

using namespace std;

CommandList::CommandList(){
    fillNormalCommands();
    fillSACommands();
}

void CommandList::fillNormalCommands(){
    normalCommands.clear();
    //add new commands here as they are implemented
    //normalCommands.emplace_back(new Command);
}

void CommandList::fillSACommands(){
    SACommands.clear();
    //add new commands here as they are implemented
    //SACommands.emplace_back(new Command);
}

vector<Command*>& CommandList::selectVector(InputState inputState){
    if(inputState == SA){
        return SACommands;
    } else {
        return normalCommands;
    }
}