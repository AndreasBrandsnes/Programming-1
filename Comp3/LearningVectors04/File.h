#pragma once
#include <string>
#include "GetTime.h"

using namespace std;

class File {
public:
    string file_name;
    int size;
    string dt;

    File()
    {
        size = 1 + rand() % 100;
        dt = get_file_timestamp();
    }
};

