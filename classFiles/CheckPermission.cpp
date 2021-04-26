#include "../headerFiles/CheckPermission.h"

bool CheckPermission::checkAccess(string path) {
    if (!access(path.c_str(), 2)) {
        return true;
    }
    return false;
}

bool CheckPermission::check_sys_proc(string path) {
    if (
            path.substr(0, 4) == "/sys" && path.size() == 4 ||
            path.substr(0, 5) == "/sys/" ||
            path.substr(0, 5) == "/proc" && path.size() == 5 ||
            path.substr(0, 6) == "/proc/") {
        return true;
    }
    return false;
}

void CheckPermission::getPermission(char *currentPath) {
    if (check_sys_proc(path)) {
        return;
    }
    DIR *dir;
    struct dirent *entry;
    char path[1024];
    struct stat info;

    cout << getType(currentPath) << '\n';

    if ((dir = opendir(currentPath)) != nullptr) {
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_name[0] != '.') {
                strcpy(path, currentPath);
                strcat(path, "/");
                strcat(path, entry->d_name);
                if (stat(path, &info) == 0) {
                    if (S_ISDIR(info.st_mode)) {
                        if (checkAccess(path)) {
                            getPermission(path);
                        }
                    } else if (S_ISREG(info.st_mode)) {
                        if (checkAccess(path)) {
                            cout << getType(path) << '\n';
                        }
                    }
                }
            }
        }
        closedir(dir);
    }
}

void CheckPermission::getPermission() {
    char *thisPath = const_cast<char *>(path.c_str());
    getPermission(thisPath);
}

string CheckPermission::getType(string path) {
    if (fs::is_regular_file(path)) return "f " + path;
    if (fs::is_directory(path)) return "d " + path;
    throw PermissionException("Error path");
}

void CheckPermission::parseFlags(int args, char **argv) {
    for (int i = 1; i < args; i += 2) {
        if (strcmp(argv[i], "-u") == 0) {
            userName = argv[i + 1];
            flagName = true;
        } else if (strcmp(argv[i], "-g") == 0) {
            groupName = argv[i + 1];
            flagGroup = true;
        } else if (strcmp(argv[i], "-p") == 0) {
            path = argv[i + 1];
            if (path.back() == '/') {
                path.pop_back();
            }
        }
    }
}

void CheckPermission::changeUID() {
    struct passwd *toChange = getpwnam(userName.c_str());
    if (toChange) {
        setuid(toChange->pw_uid);
    } else {
        throw PermissionException("User does not exist");
    }
}

void CheckPermission::changeGID() {
    struct group *toChange = getgrnam(groupName.c_str());
    if (toChange) {
        setgid(toChange->gr_gid);
    } else {
        throw PermissionException("Group does not exist");
    }
}

void CheckPermission::changeId() {
    if (flagGroup) {
        changeGID();
    }

    if (flagName) {
        changeUID();
    }

    if (!(flagName && flagGroup)) {
        throw PermissionException("Expected user name or group name");
    }
}
