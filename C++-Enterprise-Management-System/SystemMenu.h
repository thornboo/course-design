#ifndef ENTERPRISE_MANAGEMENT_SYSTEM_SYSTEMMENU_H
#define ENTERPRISE_MANAGEMENT_SYSTEM_SYSTEMMENU_H

#endif //ENTERPRISE_MANAGEMENT_SYSTEM_SYSTEMMENU_H

#pragma once

#include <iostream>
//引用头文件，即可使用全局变量SM
#include "StaffManage.h"

using namespace std;

class SystemMenu {
public:
    SystemMenu();

    ~SystemMenu();

    void mainUI();

    void run();
};

