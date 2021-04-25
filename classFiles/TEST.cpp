#include "../headerFiles/TEST.h"

void TEST::start() {
    CheckPermission cp;
    cp.path = "/home/mark/test1";
    cp.userName = "Ruslan";
    cp.groupName = "storage";
    cp.getPermission();

}
