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
#include <dirent.h>
#include <grp.h>

using namespace std;
namespace fs = std::filesystem;

class CheckPermission {
private:
    string getType(string path); // Get type of file: file or dir
    string userName, groupName, path; // This argument init by parseFlags

    bool flagName = false;
    bool flagGroup = false;

    void changeUID(); // Change ID of user
    void changeGID(); // Change ID of group
    bool checkAccess(string path);
    void getPermission(char *path); // Output on terminal

public:
    void changeId(); // Change both ID
    void getPermission();
    void parseFlags(int args, char* argv[]); // Parse flag

    friend class TEST;
};


#endif //AVRORA_CHECKPERMISSION_H
