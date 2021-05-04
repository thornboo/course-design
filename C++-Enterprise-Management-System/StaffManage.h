#ifndef ENTERPRISE_MANAGEMENT_SYSTEM_STAFFMANAGE_H
#define ENTERPRISE_MANAGEMENT_SYSTEM_STAFFMANAGE_H

#endif //ENTERPRISE_MANAGEMENT_SYSTEM_STAFFMANAGE_H


#pragma once

#include <iostream>
#include "BaseStaff.h"
#include "TechnicalStaff.h"
#include "MarketingStaff.h"
#include "ManagementStaff.h"
#include "OperatorStaff.h"
#include <string>
#include <fstream>

using namespace std;

class StaffManage {
public:
    StaffManage();

    virtual ~StaffManage();

    void addStaffInfos();     //1、增加

    void modifyStaffInfos();  //2、修改

    void deleteStaffInfos();  //3、删除

    void searchStaffInfos();  //4、查找

    void showAllStaffInfos(); //5、显示所有员工信息

    //程序启动时，将文件中的数据加载到程序中
    void readDatas();

    //在程序退出或数据发生变化时，将数据保存到文件中
    void writeDatas();

    //查找指定的成员属性是否在链表结构中存在
    BaseStaff *search(string searchKey);

    //通过使用链表操纵保存的数据
    BaseStaff *head;     //第一个对象指针
    BaseStaff *current;  //当前对象指针
    int count;           //用于计数对象
};

//声明SM为全局变量
extern StaffManage SM;
