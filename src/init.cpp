#include "../include/init.h"
#include <filesystem>
#include <iostream>

using namespace std;
using namespace filesystem;
void init() {
  if (!exists(".nit")) {
    create_directory(".nit");
    create_directory(".nit/objects");
    create_directory(".nit/refs");

#ifdef _WIN32
    SetFileAttributesA(".nit", FILE_ATTRIBUTE_HIDDEN);
#endif

    cout << "NIT REPO INITIALISED" << endl;
  } else
    cout << "NIT REPO ALREADY EXISTS" << endl;
}