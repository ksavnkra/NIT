#include <iostream>
#include "../include/init.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "NIT: COMMAND REQUIRED\nType \"nit help\" for all the nit commands\n";
        return 0;
    }
    string command = argv[1];
    if (command == "init")
    {
        init();
    }
    else if (command == "add")
    {
        cout << "File adding route";
    }
    else if (command == "commit")
        cout << "commit Route";
    else if (command == "help")
        cout << "help command";
    else
        cout << "No Command found\nType \"nit help\" for all the nit commands\n";
    return 0;
}