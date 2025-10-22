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
void bootStrap(ifstream& productsCSV, idMap idHashMap, categoryMap categoryHashMap)
{
    cout << "Welcome to Amazon Inventory System\n" << endl;
    cout << "Enter \"quit\" to exit or \"help\" to view commands:" << endl;
    
    ///READ CSV INTO BOTH CONTAINERS

    readCSVintoIDMAP(idHashMap, productsCSV);
    
    
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}

void readCSVintoIDMAP(idMap idLookup, ifstream& inputCSV){

    if (!inputCSV.is_open()){
        std::cerr <<"Cannot open the product csv for reading. "<<endl;
        return; //return, can't parse invalid CSV
    }

    std::string line;

    getline(inputCSV, line); //throwaway first line (just has categories)

    while(getline(inputCSV, line)){ //extracts one line from the csv, goes on to parse it
        std::stringstream ss(line); //create a string stream, easier parsing

        string itemID, name; //declare strings to store each product data item
        string category; //single string for category, insert multiple into product linked list

        string consumeDelim; //just to consume/skip over categories we dont need 

        //get ID
        getline(ss, itemID, ',');

        //get name
        getline(ss, name, ',');
        name = removeExtraCSVCharacters(name);

        getline(ss, consumeDelim, ','); //consume 2 categories we dont gaf about (brand name, ASIN)
        getline(ss, consumeDelim, ',');
        
        getline(ss, category, ','); 
        //create a function to get all catgories (separated by "|") and insert into the linked list

        extractCategories(category);


    }

}

string removeExtraCSVCharacters(string& improperString){

    //have to run this erase function twice, the name has back slashes too many damn times
    improperString.erase(std::remove(improperString.begin(), improperString.end(), '\"'));
    improperString.erase(std::remove(improperString.begin(), improperString.end(), '\"'));

    return improperString; //string now cleaned up
}

void extractCategories(string& categoryString){

    //working on parsing categories, need to work on cleaning up spaces and stuff :'))

    stringstream allcat(categoryString); //one string stream for all categories to parse again
    string extractedCategory;
    string garbage;

    categoryString.erase(std::remove(categoryString.begin(), categoryString.end(), '\"'));

    while(!(allcat.eof())){ //while not at the end of the string stream
        getline(allcat, extractedCategory, '|'); //each category is seperated by |
        cout<<extractedCategory;
    }


}