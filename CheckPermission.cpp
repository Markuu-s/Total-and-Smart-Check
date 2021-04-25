#include "CheckPermission.h"

void CheckPermission::getPermission() {
    for (const auto & entry : fs::recursive_directory_iterator(path)){
        cout << getType(entry.path()) << '\n';
    }
}

string CheckPermission::getType(string path) {
    if(fs::is_regular_file(path)) return "f " + path;
    if(fs::is_directory(path)) return "d " + path;
    return "ERROR PATH";
}

void CheckPermission::parseFlags(int args, char **argv) {
    for(int i = 1; i < args; i += 2){
        if (strcmp(argv[i], "-u") == 0){
            username = argv[i + 1];
        } else if (strcmp(argv[i], "-g") == 0){
            groupname = argv[i + 1];
        } else if (strcmp(argv[i], "-p") == 0){
            path = argv[i + 1];
        }
    }
}
