cmake_minimum_required(VERSION 3.19)
project(Avrora2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Avrora2 main.cpp classFiles/CheckPermission.cpp headerFiles/CheckPermission.h classFiles/TEST.cpp headerFiles/TEST.h classFiles/PermissionException.cpp headerFiles/PermissionException.h)