#ifndef ENTERPRISE_MANAGEMENT_SYSTEM_OPERATORSTAFF_H
#define ENTERPRISE_MANAGEMENT_SYSTEM_OPERATORSTAFF_H

#endif //ENTERPRISE_MANAGEMENT_SYSTEM_OPERATORSTAFF_H
#pragma once

#include "BaseStaff.h"

class OperatorStaff : public BaseStaff {
public:
    int resolveFailureRate; //故障解决率
    int workEfficiency; //工作效率
    int projectCompletion; //公司操作项目完成数
    OperatorStaff();

    ~OperatorStaff();

    void showInfos();

    void setResolveFailureRate();

    int getResolveFailureRate() const;

    void setWorkEfficiency();

    int getWorkEfficiency() const;

    void setProjectCompletion();

    int getProjectCompletion() const;
};

