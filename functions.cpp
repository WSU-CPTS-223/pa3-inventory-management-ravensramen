//these are all the function definitions for main, declaration in header

#include "header.h"

//prints menu
void printHelp()
{
    system("clear");

    cout << "Here are the commands: \n" << endl;
    cout << " 1. find - Finds if the inventory exists. Prints if item exists or is not found" << endl;
    cout << " 2. listInventory - Lists id and name of all inventory belonging to a specified category.\n    If category doesn't exist, prints 'Invalid Category'.\n"
         << endl;
    cout << " Enter \"quit\" the exit." << endl;
}

//validated input string -> checks if coresponds to menu option
bool validCommand(string line)
{
    return (line == "help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

//runs operation coresponding to user input command
void evalCommand(string line)
{
    if (line == "help")
    {
        printHelp();
    }
    // if line starts with find
    else if (line.rfind("find", 0) == 0)
    {
        // Look up the appropriate datastructure to find if the inventory exist
        cout << "YET TO IMPLEMENT!" << endl;
    }
    // if line starts with listInventory
    else if (line.rfind("listInventory") == 0)
    {
        // Look up the appropriate datastructure to find all inventory belonging to a specific category
        cout << "YET TO IMPLEMENT!" << endl;
    }
}

//Main program logic -> reads input data into data structures
void bootStrap()
{
    cout << "Welcome to Amazon Inventory System\n" << endl;
    cout << "Enter \"quit\" to exit or \"help\" to view commands:" << endl;
    
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}