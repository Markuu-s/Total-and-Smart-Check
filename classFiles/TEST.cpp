//
// Created by mark on 4/25/21.
//

#include "../headerFiles/TEST.h"


void TEST::start() {
    CheckPermission cp;
    cp.path = "/home/mark/test1/";
    cp.username = "Ruslan";
    cp.getPermission();

}
