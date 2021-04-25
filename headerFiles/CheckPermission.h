#ifndef AVRORA_CHECKPERMISSION_H
#define AVRORA_CHECKPERMISSION_H
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <unistd.h>
#include "PermissionException.h"
#include <vector>

using namespace std;
namespace fs = std::filesystem;

class CheckPermission {
private:
    string getType(string path); // Get type of file: file or dir
    string username, groupname, path; // This argument init by parseFlags
    vector<string> allPath;
public:
    void parseFlags(int args, char* argv[]); // Parse flag
    void getPermission(); // Input on terminal
    void changeUID();
    void changeGID();
    void changeId();
    bool checkAccess(string path);

    friend class TEST;
};


#endif //AVRORA_CHECKPERMISSION_H
