#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <ctype.h>

#include "gamestate.h"
using namespace std;

int main(int argc, char *argv[]) {

    bool hasWindow = true; 
    //command line inputs
    for(int i = 1; i < argc; i++){
        if(argv[i] == "-text"){
            hasWindow = false;
        }
    }

    GameState gamestate(hasWindow);

    //more command line inputs
    for(int i = 1; i < argc; i++){
        if(argv[i] == "-text"){
        } else if (argv[i] == "-seed"){
            if(++i >= argc){
                cout << "Error: Wrong number of command line arguements" << endl; 
            }
            string seed = argv[i];
            //TODO
        } else if (argv[i] == "-scriptfile1"){
            if(++i >= argc){
                cout << "Error: Wrong number of command line arguements" << endl; 
            }
            string source = argv[i];
            //TODO
        } else if (argv[i] == "-scriptfile2"){
            if(++i >= argc){
                cout << "Error: Wrong number of command line arguements" << endl; 
            }
            string source = argv[i];
            //TODO
        } else if (argv[i] == "-startlevel"){
            if(++i >= argc){
                cout << "Error: Wrong number of command line arguements" << endl; 
            }
            string level = argv[i];
            //TODO
        } else {
            cout << "Error: Invalid Command Line Argument: " << argv[i] << endl;
            return 1;
        }
    }
    
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
    return 0;
}