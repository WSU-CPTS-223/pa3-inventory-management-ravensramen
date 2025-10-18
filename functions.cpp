//these are all the function definitions for main, declaration in header

#include "header.h"

//prints menu
void printHelp()
{
    cout << "Supported list of commands: " << endl;
    cout << " 1. find <inventoryid> - Finds if the inventory exists. If exists, prints details. If not, prints 'Inventory not found'." << endl;
    cout << " 2. listInventory <category_string> - Lists just the id and name of all inventory belonging to the specified category. If the category doesn't exists, prints 'Invalid Category'.\n"
         << endl;
    cout << " Use :quit to quit the REPL" << endl;
}

//validated input string -> checks if coresponds to menu option
bool validCommand(string line)
{
    return (line == ":help") ||
           (line.rfind("find", 0) == 0) ||
           (line.rfind("listInventory") == 0);
}

//runs operation coresponding to user input command
void evalCommand(string line)
{
    if (line == ":help")
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
    cout << "\n Welcome to Amazon Inventory Query System" << endl;
    cout << " enter :quit to exit. or :help to list supported commands." << endl;
    cout << "\n> ";
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}