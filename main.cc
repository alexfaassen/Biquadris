#include <stdio.h>
#include <string>
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

    //command line inputs
    for(int i = 1; i < argc; i++){
        if(argv[i] == "-text"){
            hasWindow = false;

        } else if (argv[i] == "-seed"){

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

        } else if (argv[i] == "-scriptfile1"){
            
            //error handling out of range
            if(++i >= argc){
                cout << "Error: Wrong number of command line arguements" << endl; 
                return 1;
            }
            //read into scriptfile
            scriptfile1 = argv[i];

        } else if (argv[i] == "-scriptfile2"){
            //error handling out of range
            if(++i >= argc){
                cout << "Error: Wrong number of command line arguements" << endl; 
                return 1;
            }
            //read into scriptfile
            scriptfile2 = argv[i];

        } else if (argv[i] == "-startlevel"){
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

    GameState gamestate(hasWindow, scriptfile1, scriptfile2, startlevel);
    
    gamestate.beginReadLoop();
    
    return 0;
}