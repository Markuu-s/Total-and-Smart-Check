//
// Created by mark on 4/25/21.
//

#include "../headerFiles/PermissionException.h"

#include <utility>

const char *PermissionException::getError() {
    return m_error.c_str();
}

PermissionException::PermissionException(string error): m_error(std::move(error)) {

}


const char *PermissionException::what() const noexcept {
    return m_error.c_str();
}
