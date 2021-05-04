#ifndef ENTERPRISE_MANAGEMENT_SYSTEM_MANAGEMENTSTAFF_H
#define ENTERPRISE_MANAGEMENT_SYSTEM_MANAGEMENTSTAFF_H

#endif //ENTERPRISE_MANAGEMENT_SYSTEM_MANAGEMENTSTAFF_H
#pragma once

#include "BaseStaff.h"

using namespace std;

class ManagementStaff : public BaseStaff {
public:
    int planningSuccessRate; //策划成功率
    int targeAchievementRate;  // 企划目标达成率
    int staffManagementRate;  //员工管理率
    ManagementStaff();

    ~ManagementStaff();

    void showInfos();

    void setPlanningSuccessRate();

    int getPlanningSuccessRate() const;

    void setTargeAchievementRate();

    int getTargeAchievementRate() const;

    void setStaffManagementRate();

    int getStaffManagementRate() const;
};
