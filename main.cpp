#include "header.h"

int main(int argc, char const *argv[])
{
    string line;
    bootStrap();
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
