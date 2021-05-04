#include "SystemMenu.h"

SystemMenu::SystemMenu() {
    //从文件中读取数据
    SM.readDatas();
}

SystemMenu::~SystemMenu() {
}

//主界面菜单
void SystemMenu::mainUI() {
    cout << "-----------------------------------" << endl;
    cout << "欢迎登陆,企业员工信息管理系统！" << endl;
    cout << "【1】添加信息" << endl;
    cout << "【2】修改信息" << endl;
    cout << "【3】删除信息" << endl;
    cout << "【4】搜索信息" << endl;
    cout << "【5】显示全部信息" << endl;
    cout << "【0】退出系统" << endl;
    cout << "---------------------------------" << endl;
}

void SystemMenu::run() {

    while (1) {
        mainUI();
        cout << "-->请输入:" << endl;
        int value;
        cin >> value;

        while (value != 1 && value != 2 && value != 3 && value != 4 && value != 5 && value != 0) {
            cout << "输入格式错误，请重新输入！" << endl;
            cin.clear();
            cin >> value;
        }

        switch (value) {
            case 1:
                SM.addStaffInfos();   //增加
                break;
            case 2:
                SM.modifyStaffInfos(); //修改
                break;
            case 3:
                SM.deleteStaffInfos(); //删除
                break;
            case 4:
                SM.searchStaffInfos();  //搜索
                break;
            case 5:
                SM.showAllStaffInfos(); //显示所有信息
                break;
            case 0:
                // 保存链表中的数据
                SM.writeDatas();
                cout << "退出系统成功！" << endl;
                exit(0);
        }
    }
}
