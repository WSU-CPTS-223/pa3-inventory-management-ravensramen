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
           (line.rfind("listInventory") == 0)
           ||(line.rfind("test") == 0);
}

//runs operation coresponding to user input command
void evalCommand(idMap& idHashMap, categoryMap& categoryHashMap, const string& line)
{
    string input;
    if (line == "help") {
        printHelp();
    }
    else if (line.rfind("find", 0) == 0) {
        cout<<"Input ID: ";
       cin>>input;
        idHashMap.findProduct(input);
    }
    else if (line.rfind("listInventory", 0) == 0) {
        cout<<"Input category: ";
        cin>>input;
        categoryHashMap.listCategoryItems(input);
    }
    else if(line.rfind("test", 0)== 0 ){
        cout<<"You have reached the top secret testFunction field";
        //create an instance of test functions object
    }
}

//Main program logic -> reads input data into data structures
void bootStrap(ifstream& productsCSV, idMap& idHashMap, categoryMap& categoryHashMap)
{
    cout << "Welcome to Amazon Inventory System\n" << endl;
    cout << "Enter \"quit\" to exit or \"help\" to view commands:" << endl;
    
    ///READ CSV INTO BOTH CONTAINERS
    readCSVintoMAPS(idHashMap, categoryHashMap, productsCSV);


    //printCategoryMap(categoryHashMap);//FOR DEBUGGING, REPLACE W TEST CASE
    
}

//Function that parses CSV into map containers
void readCSVintoMAPS(idMap& idLookup, categoryMap& categoryHashMap, ifstream& inputCSV){

    if (!inputCSV.is_open()){
        std::cerr <<"Cannot open the product csv for reading. "<<endl;
        return; //return, can't parse invalid CSV
    }

    std::string line; //stores each line of CSV
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
        name = removeExtraCSVCharacters(name); //remove backslash/space characters

        getline(ss, consumeDelim, ','); //consume 2 categories we dont need about (brand name, ASIN)
        getline(ss, consumeDelim, ',');
        
        getline(ss, category, ','); 
        //create a function to get all catgories (separated by "|") and insert into the linked list

        extractCategories(category, categories);

    //store all product fields in productData object
        productData product(itemID, name, categories); 
        
    //insert into id map
        idLookup.insert(itemID, product); 
        
        //to iterate through the products categories
        itemCategory* iterator = categories.getHead();
    
    //for each product, add it to every category it matches
    while (iterator != nullptr) { 
        categoryHashMap.addProductToCategory(iterator->data, product); // Use iterator->data
        iterator = iterator->next;
        }

        continue; //skips rest of the line -> goes to next iteration (we extracted all the required info)
        
        //FOR TESTING, REPLACE WITH TEST CASE LATER
        printCategoryMap(categoryHashMap);
    }

}

//remove extra characters for consistency (before inserting into container)
string removeExtraCSVCharacters(string& improperString) {
    // remove all double quotes from the string
    improperString.erase(
        std::remove(improperString.begin(), improperString.end(), '\"'),
        improperString.end()
    );

    return improperString; // return the cleaned-up string
}

//Category field may contain many categories -> add each category found to linked list
void extractCategories(string& categoryString, categoryList& categories){

    categoryList itemCategories;

    categoryString.erase( //erase extra characters in entire string
    std::remove(categoryString.begin(), categoryString.end(), '\"'),
    categoryString.end()
    );

    stringstream ss(categoryString); //one string stream for all categories to parse individual categories
    string category;


    while(getline(ss, category, '|')){ //while not at the end of the string stream, separate by | symbol
        
    category.erase(category.begin(), find_if(category.begin(), category.end(), [](unsigned char ch) {
        return !isspace(ch); //isspace function looks for whitespace characters, returns non whitespace chars
    }));
    category.erase(find_if(category.rbegin(), category.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), category.end());

    
    categories.addBack(category); //add each read category to the linked list of categories
    }

}


void findIfIDExists(idMap &idHashMap, string ID){
    
    idHashMap.findProduct(ID); //container has a function to print message if found

}


void findItemsInCategory(categoryMap &catMap, string Category){

    catMap.listCategoryItems(Category);

}

















////////////////////FOR DEBUG, REPLACE WITH TESTCASE LATER ////////////////////////////////////////////////////////////////////
void printCategoryMap(categoryMap& cmap) {
    //std::vector<std::string> testCategories = {"Sports & Outdoors"};
    list<productData>* item = cmap.find("Sports & Outdoors");
    
    //prints out every item that is under given category
    for (const auto& p : *item) {
            cout << " - " << p.getID() << " : " << p.getName() << endl;
    }
}

