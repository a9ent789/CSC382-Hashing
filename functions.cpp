//Tecumseh McMullin
//CSC382
//functions.cpp

//Including libraries
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <list>
#include "functions.h"
//Keeping me from having to use std::
using namespace std;

//This is the constructor function for the table class.
table::table(int key){
    //This sets the key
    this->key = key;
    //This creates a list within a list
    hashT = new list<string>[key];
}

//This is the insert function to insert new strings into the hash table.
void table::insertS(string d){ 
    int inputL;
    string hashO;
    string temp;
    //This gets the key by using the hashKey function.
    int key = hashKey(d);
    //This gets the lenght of the input
    inputL = d.length();
    //This creates a constant for an array based on the input lenght
    const int arrL = inputL + 1;
    //This creates an array for the users input
    char* strtochar = new char[arrL];
    //This copies the string and places it into the array
    strcpy(strtochar, d.c_str());
    //This for loop turns the array back into an encrypted string.
    for (int i = 0; i < arrL; i++){
        strtochar[i]=strtochar[i]+5;
        temp = temp + strtochar[i];
    }

    //This pushes the string into the list.
    hashT[key].push_back(temp);
}

//This function gets the key for the list.
int table::hashKey(string d){
    int inputL;
    string hashO;
    //This gets the lenght of the input
    inputL = d.length();
    //This creates a constant for an array based on the input lenght
    const int arrL = inputL + 1;
    //This creates an array for the users input
    char* strtochar = new char[arrL];
    //This copies the string and places it into the array
    strcpy(strtochar, d.c_str());

    //This returns the first letter of the string and gets the key.
    return strtochar[0] % this->key;
}

//This displays the entire list.
void table::displayTable(){
    for (int i = 0; i < key; i++){
        cout << i << endl;
        for (auto x: hashT[i]){
            cout << " " << x << endl;
        }
    }
}

//This displays the menu for the user.
void menu(){
    int val = 26;
    int rand1;
    bool stay = true;
    int choice;
    string sInput;
    table hashT1(val);
    //This is a while loop to keep the menu going.
    while(stay){
        cout << "Hashed menu" << endl;
        cout << "1. enter text" << endl;
        cout << "2. display table" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;
        //This is a switch case statement that runs the functions based on the user input.
        switch(choice){
            case 1:
                cin.ignore();
                cout << "Enter what you would like to hash" << endl;
                getline(cin, sInput);
                hashT1.insertS(sInput);
                break;
            case 2:
                hashT1.displayTable();
                break;
            case 3:
                cout << "Goodbye" << endl;
                stay = false;
                break;
            default:
                cout << "Please try again" << endl;
                break;
        }
    }
}
