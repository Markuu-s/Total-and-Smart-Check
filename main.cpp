#include <iostream>
#include <filesystem>
#include "CheckPermission.h"
using namespace std;

int main(int argc, char *argv[]){


    CheckPermission cp;
    cp.parseFlags(argc, argv);
    cp.getPermission();

    return 0;
}