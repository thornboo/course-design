cmake_minimum_required(VERSION 3.17)
project(Enterprise_Management_System)

set(CMAKE_CXX_STANDARD 14)

add_executable(Enterprise_Management_System main.cpp SystemMenu.h StaffManage.h BaseStaff.h BaseStaff.cpp StaffManage.cpp SystemMenu.cpp TechnicalStaff.h TechnicalStaff.cpp MarketingStaff.cpp MarketingStaff.h ManagementStaff.h ManagementStaff.cpp OperatorStaff.h OperatorStaff.cpp)