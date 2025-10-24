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

    readCSVintoMAPS(idHashMap, categoryHashMap, productsCSV);


    printCategoryMap(categoryHashMap);//FOR DEBUGGING, REPLACE W TEST CASE
    
    // TODO: Do all your bootstrap operations here
    // example: reading from CSV and initializing the data structures
    // Don't dump all code into this single function
    // use proper programming practices
}

void readCSVintoMAPS(idMap idLookup, categoryMap categoryHashMap, ifstream& inputCSV){

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
        categoryList categories; //linked list to store all categories read

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

        extractCategories(category, categories);

        //create an instance productData now that all fields are extracted from CSV
        productData product(itemID, name, categories); 
        
        idLookup.insert(itemID, product); //insert into the map, id is the key, product data as the data
        
        //populate category map, place product data in index spot for each category it fits into
    itemCategory* iterator = categories.getHead();

    while (iterator != nullptr) { 
        categoryHashMap.addProductToCategory(iterator->data, product); // Use iterator->data
        iterator = iterator->next;
        }

        continue; //skips rest of the line -> goes to next iteration (we extracted all the required info)
    
    }

}

string removeExtraCSVCharacters(string& improperString) {
    // remove all double quotes from the string
    improperString.erase(
        std::remove(improperString.begin(), improperString.end(), '\"'),
        improperString.end()
    );

    return improperString; // return the cleaned-up string
}

void extractCategories(string& categoryString, categoryList& categories){

    categoryList itemCategories;
    //working on parsing categories, need to work on cleaning up spaces and stuff :'))

    categoryString.erase(
    std::remove(categoryString.begin(), categoryString.end(), '\"'),
    categoryString.end()
    );

    stringstream ss(categoryString); //one string stream for all categories to parse again
    string category;


    while(getline(ss, category, '|')){ //while not at the end of the string stream
        
    category.erase(category.begin(), find_if(category.begin(), category.end(), [](unsigned char ch) {
        return !isspace(ch); //isspace function looks for whitespace characters, returns non whitespace chars
    }));
    category.erase(find_if(category.rbegin(), category.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), category.end());

    
    categories.addBack(category); //add each read category to the linked list of categories
    }

}

////////////////////FOR DEBUG, REPLACE WITH TESTCASE LATER

void printCategoryMap(categoryMap& cmap) {
    std::vector<std::string> testCategories = {"Sports & Outdoors"};

    for (const auto& cat : testCategories) {
        std::cout << "Category: " << cat << std::endl;

        list<productData>* products = cmap.find(cat);
        if (!products || products->empty()) {
            std::cout << "  No products found.\n";
            continue;
        }

        for (const auto& p : *products) {
            // Use the getters from productData
            std::cout << "  - " << p.getID() << " : " << p.getName() << std::endl;

            // Optionally print categories for this product
            // p.printCategories();
        }

        std::cout << std::endl;
    }
}