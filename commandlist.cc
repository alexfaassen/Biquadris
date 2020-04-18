#include "commandlist.h"
//include the .h of all of the command subclasses too
#include "blind.h"
#include "clockwisecmd.h"
#include "counterclockwisecmd.h"
#include "downcmd.h"
#include "dropcmd.h"
#include "force.h"
#include "heavy.h"
#include "icmd.h"
#include "jcmd.h"
#include "lcmd.h"
#include "leftcmd.h"
#include "leveldown.h"
#include "levelup.h"
#include "norandom.h"
#include "ocmd.h"
#include "random.h"
#include "restart.h"
#include "rightcmd.h"
#include "scmd.h"
#include "sequence.h"
#include "tcmd.h"
#include "zcmd.h"

using namespace std;

CommandList::CommandList(){
    fillNormalCommands();
    fillSACommands();
}

CommandList::~CommandList(){
    for(auto p : normalCommands){
        delete p;
    }
    for (auto p : SACommands){
        delete p;
    }
}

void CommandList::fillNormalCommands(){
    normalCommands.clear();
    // movement commands
    normalCommands.emplace_back(new LeftCmd());
    normalCommands.emplace_back(new RightCmd());
    normalCommands.emplace_back(new DropCmd());
    normalCommands.emplace_back(new DownCmd());
    normalCommands.emplace_back(new ClockwiseCmd());
    normalCommands.emplace_back(new CounterClockwiseCmd());
    // level commands
    normalCommands.emplace_back(new LevelUp());
    normalCommands.emplace_back(new LevelDown());
    // restart
    normalCommands.emplace_back(new Restart());
    // testing commands
    normalCommands.emplace_back(new NoRandom());
    normalCommands.emplace_back(new Random());
    normalCommands.emplace_back(new Sequence());
    normalCommands.emplace_back(new ICmd());
    normalCommands.emplace_back(new JCmd());
    normalCommands.emplace_back(new LCmd());
    normalCommands.emplace_back(new OCmd());
    normalCommands.emplace_back(new SCmd());
    normalCommands.emplace_back(new ZCmd());
    normalCommands.emplace_back(new TCmd());;
}

void CommandList::fillSACommands(){
    SACommands.clear();
    SACommands.emplace_back(new Force());
    SACommands.emplace_back(new Heavy());
    SACommands.emplace_back(new Blind());
}

vector<Command*>& CommandList::selectVector(InputState inputState){
    if(inputState == SA){
        return SACommands;
    } else {
        return normalCommands;
    }
}
