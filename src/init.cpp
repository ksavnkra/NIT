#include "../include/init.h"
#include <filesystem>
#include <iostream>

using namespace std;

void init() {
  if (!filesystem::exists(".nit")) {
    filesystem::create_directory(".nit");
    filesystem::create_directory(".nit/objects");
    filesystem::create_directory(".nit/refs");

#ifdef _WIN32
    SetFileAttributesA(".nit", FILE_ATTRIBUTE_HIDDEN);
#endif

    cout << "NIT REPO INITIALISED" << endl;
  } else
    cout << "NIT REPO ALREADY EXISTS" << endl;
}