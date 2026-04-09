#include "../include/commit.h"
#include "../include/hash_object.h"
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace filesystem;

void commit(const string &message) {
  if (!exists(".nit")) {
    cout << "ERROR: NOT A NIT REPOSITORY (Run 'nit init' first!)\n";
    return;
  }

  if (!exists(".nit/index")) {
    cout << "ERROR: STAGING AREA EMPTY (Run 'nit add' first!)\n";
    return;
  }

  time_t timestamp = time(0);
  ifstream indexFile(".nit/index", ios::binary);
  stringstream ss;
  ss << indexFile.rdbuf();
  indexFile.close();
  string tree_data = ss.str();
  string tree_hash = hashingSha1(tree_data);
  string commitMessage = "tree";
  commitMessage += '\0';
  commitMessage += tree_hash + "\ntime";
  commitMessage += '\0';
  commitMessage += string(ctime(&timestamp)) + "\n" + message;
  commitMessage += '\0';
  commitMessage += '\n';
  commitMessage =
      "Commit " + to_string(commitMessage.size()) + '\0' + commitMessage;
  string hashedMessage = hashingSha1(commitMessage);

  ofstream writeFile(".nit/objects/" + hashedMessage, ios::binary);
  writeFile.write(commitMessage.c_str(), commitMessage.size());
  cout << "Commit created!" << endl;
}