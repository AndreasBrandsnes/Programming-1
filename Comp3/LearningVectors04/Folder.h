#pragma once
#include <string>
#include <vector>
#include "File.h"

using namespace std;

class Folder {
public:
    string folder_name;
    vector<File> files;
};
