#include "headerFiles/CheckPermission.h"
#include "headerFiles/TEST.h"
using namespace std;

int main(int argc, char *argv[]){

/*    TEST t;
    t.start();
    return 0;
*/
    CheckPermission cp;
    cp.parseFlags(argc, argv);
    cp.changeId();
    cp.getPermission();

    return 0;
}