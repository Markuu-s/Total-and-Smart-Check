#include <cassert>
#include "../headerFiles/CheckPermission.h"

bool CheckPermission::checkAccess(string path) {

    if (!access(path.c_str(), 4)){
        return true;
    }
    return false;
}

void CheckPermission::getPermission() {
    struct stat buf;

    for (const auto &entry : fs::recursive_directory_iterator(path)) {
        allPath.push_back(entry.path());
    }

    changeUID();
    for(auto& entry : allPath){
        if (checkAccess(entry)) {
            cout << getType(entry) << '\n';
        }
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

void CheckPermission::changeUID() {
    struct passwd *toChange = getpwnam(username.c_str());;
    setuid(toChange->pw_uid);
}

void CheckPermission::changeGID() {
    struct passwd *toChange = getpwnam(groupname.c_str());
    setgid(toChange->pw_uid);
}

void CheckPermission::changeId() {
    changeUID();
    changeGID();
}