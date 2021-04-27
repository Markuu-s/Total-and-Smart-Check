#include "../headerFiles/TEST.h"

void TEST::start() {
    CheckPermission cp;
    cp.path = "/";
    cp.userName = "mark";
    cp.groupName = "sudo";
    cp.getPermission();

}
