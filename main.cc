#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <ctype.h>

#include "gamestate.h"
using namespace std;

int main(int argc, char *argv[]) {

    
    //TODO: command line inputs
    hasWindow = true; 

    GameState gamestate(hasWindow);
    
    string s;
    while (in >> s) {
        int multiplier = 1;
        
        if(isdigit(s[0])){          // test if s starts with an int
            multiplier = atoi(s);   // http://www.cplusplus.com/reference/cstdlib/atoi/

            // clear all digits from front of string
            while(isdigit(s[0])){
                s.erase(s[0]);
            }
        }

        gamestate.runInput(s, multiplier);
    }

}