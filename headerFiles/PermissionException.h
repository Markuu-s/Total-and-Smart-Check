//
// Created by mark on 4/25/21.
//

#ifndef AVRORA2_PERMISSIONEXCEPTION_H
#define AVRORA2_PERMISSIONEXCEPTION_H
#include <string>
using namespace std;

class PermissionException {
private:
    string m_error;
public:
    explicit PermissionException(string error);
    const char* getError();
    const char* what() const noexcept;

    virtual ~PermissionException();
};


#endif //AVRORA2_PERMISSIONEXCEPTION_H
