//Tecumseh McMullin
//CSC382
//functions.h

//Including libraries
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <list>

//keeping me from having to use std::
using namespace std;

//This is the class that holds the link list for the hash table.
class table{
    //declaring variables for the class.
    int key;
    list <string>* hashT;
public:
    //this creates the class
    table(int key);
    //This inserts the string into the class.
    void insertS(string d);
    //this gets the key for the hash.
    int hashKey(string d);
    //this displays the hash table
    void displayTable();
};