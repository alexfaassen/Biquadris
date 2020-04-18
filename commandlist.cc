#include "commandlist.h"
// movement commands
#include "leftcmd.h"
#include "rightcmd.h"
#include "downcmd.h"
#include "dropcmd.h"
#include "clockwisecmd.h"
#include "counterclockwisecmd.h"
// level commands
#include "levelup.h"
#include "leveldown.h"
// restart
#include "restart.h"
// testing commands
#include "norandom.h"
#include "random.h"
#include "sequence.h"
#include "icmd.h"
#include "jcmd.h"
#include "lcmd.h"
#include "ocmd.h"
#include "scmd.h"
#include "zcmd.h"
#include "tcmd.h"
// SA Commands
#include "force.h"
#include "heavy.h"
#include "blind.h"

using namespace std;

CommandList::CommandList(){
    fillNormalCommands();
    fillSACommands();
}

void CommandList::fillNormalCommands(){
    normalCommands.clear();
    // Normal Commands
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
    normalCommands.emplace_back(new TCmd());
}

void CommandList::fillSACommands(){
    SACommands.clear();
    // SA Commands
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
