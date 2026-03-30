#include "../include/hash_object.h"
#include <fstream>
#include <iostream>
#include <openssl/sha.h>
#include <sstream>
#include <string>

using namespace std;

string hashingSha1(const string &content) {
  unsigned char hash[20];
  SHA1((unsigned char *)content.c_str(), content.size(), hash);
  string hexaBase = "0123456789abcdef";
  string hashedContent = "";

  for (int i = 0; i < 20; i++) {
    hashedContent.push_back(hexaBase[hash[i] / 16]);
    hashedContent.push_back(hexaBase[hash[i] % 16]);
  }
  return hashedContent;
}

void hashObject(const string &filename) {
  ifstream fileRead(filename, ios::binary);
  if (!fileRead)
    cout << "ERROR OPENING THE FILE\nMIGHT BE POSSIBLE FILE DOESN'T EXIST, "
            "KINDLY CHECK\n";
  stringstream ss;
  ss << fileRead.rdbuf();
  fileRead.close();
  string content = ss.str();
  string header = "Nakra " + to_string(content.size()) + '\0';
  string combination = header + content;
  string hashedFileData = hashingSha1(combination);
  ofstream fileWrite(".nit/objects/" + hashedFileData, ios::binary);
  fileWrite.write(combination.c_str(), combination.size());
  cout << hashedFileData << endl;
}