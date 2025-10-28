//Sydnee Boothby
//PA 3 - Amazon Inventory Navigator
//CPTS 223 Subu Kandaswamy
//10/18

//TO:DO
//line 88 of functions.cpp error

//ADD TEST CASES

//declaration of functions and libraries used by main
//descriptions in .cpp

#include <iostream>
#include <string>
#include <cstdlib>

#include <fstream> //for csv file reading
#include <sstream>

#include <list>
#include<vector>

#include "derivedMaps.cpp"

using namespace std;
using std::ifstream;

void printHelp();

bool validCommand(string line);

void evalCommand(idMap& idHashMap, categoryMap& categoryHashMap, const string& line);

void bootStrap(ifstream& productsCSV, idMap& idHashMap, categoryMap& categoryHashMap);

void readCSVintoMAPS(idMap& idLookup, categoryMap& categoryHashMap, ifstream& inputCSV);

string removeExtraCSVCharacters(string& improperString);

void extractCategories(string& categoryString, categoryList& categories);

//void printCategoryMap(categoryMap& cmap); //FOR DEBUG, REPLACE WITH TESTCASES

void findIfIDExists(idMap &idHashMap, string ID);

void findItemsInCategory(categoryMap &catMap, string Category);

void testCASES();