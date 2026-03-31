#include "../include/cat-file.h"
#include "../include/hash_object.h"
#include "../include/init.h"
#include "../include/status.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "NIT: COMMAND REQUIRED\nType \"nit help\" for all the nit "
            "commands\n";
    return 0;
  }
  string command = argv[1];
  if (command == "init")
    init();
  else if (command == "add")
    cout << "File adding route";
  else if (command == "commit")
    cout << "commit Route";
  else if (command == "help")
    cout << "help command";
  else if (command == "status")
    status();
  else if (command == "hash-object") {
    if (argc >= 3)
      hashObject(argv[2]);
    else
      cout << "ERROR: YOU MUST PROVIDE A FILE NAME TO HASH!\nfor e.g. \n\"nit "
              "hash-object file.txt\"\n";
  } else if (command == "cat-file") {
    if (argc >= 3) {
      cout << catFile(argv[2]);
    } else {
      cout << "ERROR: MUST PROVIDE A HASH\n";
    }
  } else
    cout << "No Command found\nType \"nit help\" for all the nit commands\n";
  return 0;
}
