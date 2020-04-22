#include <string>
#include <string.h>
#include <cstdlib>
#include <ctype.h>
#include <iostream>

#include "gamestate.h"

using namespace std;

int main(int argc, char *argv[]) {

    bool hasWindow = true; 
    int seed;
    bool setSeed = false;
    string scriptfile1 = "sequence1.txt";
    string scriptfile2 = "sequence2.txt";
    int startlevel = 0;
    bool simul = false;
    bool fastmode = false;

    //command line inputs
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-text") == 0){
            hasWindow = false;

        } else if (strcmp(argv[i], "-simul") == 0){
            simul = true;
        } else if (strcmp(argv[i], "-fast") == 0){
            fastmode = true;
        } else if (strcmp(argv[i], "-seed") == 0){

            //error handling out of range
            if(++i >= argc){
                cout << "Error: Wrong number of command line arguements" << endl; 
                return 1;
            }
            //read into seed
            try {
                seed = stoi(argv[i]);
                setSeed = true;
            } catch (invalid_argument){
                cout << "Error: seed must be an int" << endl;
                return 1;
            }

        } else if (strcmp(argv[i], "-scriptfile1") == 0){
            
            //error handling out of range
            if(++i >= argc){
                cout << "Error: Wrong number of command line arguements" << endl; 
                return 1;
            }
            //read into scriptfile
            scriptfile1 = argv[i];

        } else if (strcmp(argv[i], "-scriptfile2") == 0){
            //error handling out of range
            if(++i >= argc){
                cout << "Error: Wrong number of command line arguements" << endl; 
                return 1;
            }
            //read into scriptfile
            scriptfile2 = argv[i];

        } else if (strcmp(argv[i], "-startlevel") == 0){
            //error handling out of range
            if(++i >= argc){
                cout << "Error: Wrong number of command line arguements" << endl; 
                return 1;
            }
            //read into startlevel
            try {
                startlevel = stoi(argv[i]);
            } catch (invalid_argument){
                cout << "Error: startlevel must be an int" << endl;
                return 1;
            }

        } else {
            cout << "Error: Invalid Command Line Argument: " << argv[i] << endl;
            return 1;
        }
    }

    //set random seed if seed hasn't been set
    if(!setSeed){
        srand(time(NULL));
    } else {
        srand(seed);
    }

    //cout << "test: before gamestate" << endl;

    GameState gamestate(hasWindow, scriptfile1, scriptfile2, startlevel, simul, fastmode);

    //cout << "test: before beginReadLoop" << endl;
    
    gamestate.beginReadLoop();
    
    return 0;
}