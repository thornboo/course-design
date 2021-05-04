#ifndef ENTERPRISE_MANAGEMENT_SYSTEM_BASESTAFF_H
#define ENTERPRISE_MANAGEMENT_SYSTEM_BASESTAFF_H

#endif //ENTERPRISE_MANAGEMENT_SYSTEM_BASESTAFF_H


#pragma once

#include <string>
#include <iostream>

using namespace std;

class BaseStaff {
public:
    BaseStaff();

    ~BaseStaff();

    //成员函数
    void setStaffNumber(); //工号

    string getStaffNumber() const;

    void setStaffName(); //姓名

    string getStaffName() const;

    void setStaffSex(); // 性别

    string getStaffSex() const;

    void setWorkYears(); //工龄

    int getWorkYears() const;

    void setStaffSalary(); //工资

    int getStaffSalary() const;

    void setStaffGrade();

    int getStaffGrade() const; //等级

    //友元方式"<<"运算符重载
    friend void operator<<(ostream &out, BaseStaff *a);


    //成员属性(6个基础属性)
    string staffNumber;      //工号
    string staffName;        //姓名
    string staffSex;         //性别
    int staffWorkYears;      //工龄
    int staffSalary;         //工资
    int staffGrade;          //等级

    int staffDutyType;       //部门：1-技术，2-营销，3-管理，4-操作
    int technology;
    int devote;

    int totalAnnualSales;
    int customerReception;

    int planningSuccessRate; //策划成功率
    int targeAchievementRate;  // 企划目标达成率
    int staffManagementRate;  //员工管理率

    int resolveFailureRate; //故障解决率
    int workEfficiency; //工作效率
    int projectCompletion; //公司操作项目完成数

    BaseStaff *next;     //链表形式保存数据

    virtual void showInfos() = 0;
};
