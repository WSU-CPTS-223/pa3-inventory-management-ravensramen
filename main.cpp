#include "header.h"

int main(int argc, char const *argv[])
{

    idMap idLookup;
    categoryMap categoryLookup;

    //create inputfile stream for parsing
    ifstream productsCSV("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv");

    string line;
    bootStrap(productsCSV, idLookup, categoryLookup);
    while (getline(cin, line) && line != "quit") //read user input until exit/quit
    {
        if (validCommand(line))
        {
            evalCommand(line);
        }
        else
        {
            cout << "Command not supported. Enter \"help\" to view commands" << endl;
        }
        cout << "> ";
    }
    return 0;
}
