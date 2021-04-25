#include <iostream>
#include <filesystem>
#include <sys/types.h>
#include <pwd.h>
#include "CheckPermission.h"
#include "TEST.h"
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