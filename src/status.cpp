#include <filesystem>
#include <iostream>

using namespace std;
using namespace filesystem;

void status() {
  if (exists(".nit"))
    cout << "NIT REPO ALREADY EXISTS" << endl;
}