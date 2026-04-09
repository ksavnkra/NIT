#include "../include/hash_object.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;
using namespace filesystem;
void add(const string &filename) {
  if (!exists(filename)) {
    cout << "ERROR: THE FILE YOU ENTERED DOESN'T EXIST\n";
    return;
  }
  string fileHash = hashObject(filename);
  if (fileHash == "")
    return;
  map<string, string> indexMap;
  ifstream inFile(".nit/index");
  string fName, fHash;

  while (getline(inFile, fName, '\0')) {
    getline(inFile, fHash, '\n');
    indexMap[fName] = fHash;
  }
  inFile.close();

  if (indexMap.count(filename) && indexMap[filename] == fileHash) {
    cout << "NO CHANGES IN FILE\n";
    return;
  }
  indexMap[filename] = fileHash;
  ofstream indexFile(".nit/index");
  for (auto const &[key, val] : indexMap) {
    indexFile << key << '\0' << val << '\n';
  }
  cout << "Added " << filename << " to the index!" << endl;
}