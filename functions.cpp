//Tecumseh McMullin
//CSC382
//functions.cpp

//Including libraries
#include <iostream>
#include <string>
#include <cstring>

//Keeping me from having to use std::
using namespace std;

//This is a void function that holds the hashing algorithm
void hashing(){
    //Declaring a constant for the hex array
    const int HEX = 16;
    //This is the hex array
    char hexValue[HEX];
    //User input for what they want hashed
    string hashInput;
    //This is for the length of the input
    int inputL;
    //This is so that it can help change the algorithm
    char saltA;

    //This is a for loop that creates an array that holds hexidecimal values
    for (int i = 0; i < HEX; i++){
        if (i <= 9){
            hexValue[i] = i + 48;
        }
        else {
            hexValue[i] = i + 55;
        }
    }
    //output for instructions
    cout << "please enter what you would like to be hashed" << endl;
    cout << "User Input : ";
    //This ignores the enter from the input for the previous menu
    cin.ignore();
    //This gets the input as a string for the program
    getline(cin, hashInput);

    //If the user doesn't input anything
    if(hashInput == ""){
        cout << "Input invalid, returning to menu" << endl;
    }

    //If the user inputs something.
    else{
        //This gets the lenght of the input
        inputL = hashInput.length();
        //This creates a constant for an array based on the input lenght
        const int arrL = inputL + 1;
        //This creates an array for the users input
        char* strtochar = new char[arrL];
        //This copies the string and places it into the array
        strcpy(strtochar, hashInput.c_str());
        cout << "Hashed Output : ";
        //This makes sure that the input length isn't too high for the algorithm
        inputL = inputL % 10;
        //This is a for loop that hashes the input
        for (int i = 0; i < arrL; i++) {

            //If it is the first run through it will grab the "salt"
            if (i == 0){
                //grabs the salt value
                saltA = strtochar[i];
                //Algorithm to turn into hexidecimal
                strtochar[i] = strtochar[i] + saltA;
                strtochar[i] = strtochar[i] * inputL; 
                strtochar[i] = strtochar[i] % 16;
                
                //If the value ends up being negative it turns it positive
                if ((int)strtochar[i]<=0){
                    strtochar[i] = strtochar[i] * (-1);
                }
                
                //generates a hex value based on the ascii value from the algorithm
                strtochar[i] = hexValue[strtochar[i]];
            }
            //All the times thats not the first
            else{
                //Algorithm to turn into hexidecimal
                strtochar[i] = strtochar[i] + saltA;
                strtochar[i] = strtochar[i] * inputL;
                strtochar[i] = strtochar[i] % 16;
                //If the value ends up being negative it turns it positive
                if ((int)strtochar[i]<=0){
                    strtochar[i] = strtochar[i] * (-1);
                }
                
                //generates a hex value based on the ascii value from the algorithm
                strtochar[i] = hexValue[strtochar[i]];
            }
            //Outputs the hashed value
            cout << strtochar[i];
        }
        //skips line for readability
        cout << "" << endl;
    }
}

//This is a menu that returns a bool value for exit
bool runMenu(){
    //Declaring variables
    bool stay = true;
    //Choice is character just incase they try to put a letter instead of a number
    char choice;
    //A while loop that keeps the user in the loop until they want to exit
    while (stay) {
        cout << "Hashing program" << endl;
        cout << "_______________" << endl;
        cout << "1. Hash a Word" << endl;
        cout << "2. Exit" << endl;
        //Gets user input for the switch case statement
        cin >> choice;
        //Switch case statement that decides based on user input
        switch (choice) {
            //This case runs the hashing algorithm
            case '1':
                hashing();
                stay = true;
                break;
            //This case exits the program
            case '2':
                cout << "Goodbye" << endl;
                stay = false;
                break;
            //If the user inputs an incorrect variable
            default:
                cout << "Incorrect input" << endl;
                stay = true;
                break;

        }
    }

    //returns the bool if the user decides to exit or not.
    return stay;
}