#ifndef AVRORA_CHECKPERMISSION_H
#define AVRORA_CHECKPERMISSION_H
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <cstring>
using namespace std;
namespace fs = std::filesystem;

class CheckPermission {
private:
    string getType(string path); // Get type of file: file or dir
    string username, groupname, path; // This argument init by parseFlags
public:
    void parseFlags(int args, char* argv[]); // Parse flag
    void getPermission(); // Input on terminal
};


#endif //AVRORA_CHECKPERMISSION_H
