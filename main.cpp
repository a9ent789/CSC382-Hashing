//Tecumseh McMullin
//CSC382
//main.cpp

//Including libraries
#include <iostream>
#include <string>
#include <cstring>

//Including the .h file
#include "functions.h"

//keeping me from having to use std::
using namespace std;

//This is the main function that runs the program
int main(){
    //declaring menu variable
    bool menu = true;
    //A while loop that exits when the user wants to exit the program.
    while(menu){
        menu = runMenu();
    }
    //Returns 0 to the program.
    return 0;
}