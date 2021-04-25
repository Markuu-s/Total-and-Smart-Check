#include <iostream>
#include <filesystem>
#include <sys/types.h>
#include <pwd.h>
#include "headerFiles/CheckPermission.h"
#include "headerFiles/TEST.h"
using namespace std;

int main(int argc, char *argv[]){

    TEST test;
    test.start();
    return 0;
    CheckPermission cp;
    //cp.parseFlags(argc, argv);


    cp.getPermission();

    //auto a = getpwnam("mark");
    //cout << 'a';



    return 0;
}