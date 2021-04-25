//
// Created by mark on 4/25/21.
//

#include "TEST.h"
#include "CheckPermission.h"

void TEST::start() {
    CheckPermission cp;
    cp.path = "/home/mark/test";
    cp.username = "mark";
    cp.changeUID();
    //cp.getPermission();
}
