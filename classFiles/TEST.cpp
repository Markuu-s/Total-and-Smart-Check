#include "../headerFiles/TEST.h"

void TEST::start() {
    CheckPermission cp;
    cp.path = "/";
    cp.userName = "Ruslan";
    cp.groupName = "storage";
    cp.getPermission();

}
