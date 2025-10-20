//Sydnee Boothby
//PA 3 - Amazon Inventory Navigator
//CPTS 223 Subu Kandaswamy
//10/18

//TO:DO
//work on parsing CSV
//test maps

//declaration of functions and libraries used by main
//descriptions in .cpp

#include <iostream>
#include <string>
#include <cstdlib>

#include <fstream> //for csv file reading
#include <sstream>

#include "derivedMaps.cpp"

using namespace std;

void printHelp();

bool validCommand(string line);

void evalCommand(string line);

void bootStrap();
