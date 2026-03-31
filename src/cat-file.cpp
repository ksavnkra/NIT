#include "../include/cat-file.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
using namespace filesystem;

string catFile(const string &hash) {
  string path = ".nit/objects/" + hash;
  if (!exists(path)) {
    cout << "ERROR: NO SUCH HASH FOUND\n";
    return "";
  }
  stringstream ss;
  ifstream file(path, ios::binary);
  ss << file.rdbuf();
  string content = ss.str();
  for (int i = 0; i < content.size(); i++) {
    if (content[i] == '\0')
      return content.substr(i + 1);
  }
  return "";
}