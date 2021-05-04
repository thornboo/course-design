#include "BaseStaff.h"

BaseStaff::BaseStaff() {}

BaseStaff::~BaseStaff() {}

// 设置工号
void BaseStaff::setStaffNumber() {
    cout << "-->工号:";
    cin >> this->staffNumber;
}

// 获取工号
string BaseStaff::getStaffNumber() const {
    return this->staffNumber;
}

// 设置姓名
void BaseStaff::setStaffName() {
    cout << "-->姓名:";
    cin >> this->staffName;
}

// 获取姓名
string BaseStaff::getStaffName() const {
    return this->staffName;
}

// 设置性别
void BaseStaff::setStaffSex() {
    cout << "-->性别:";
    cin >> this->staffSex;
    while (staffSex != "男" && staffSex != "女") {
        cout << "输入格式错误，请重新输入！" << endl;
        cin.clear();
        cin >> this->staffSex;
    }
}

// 获取性别
string BaseStaff::getStaffSex() const {
    return this->staffSex;
}

// 设置工龄
void BaseStaff::setWorkYears() {
    cout << "-->工龄:";
    cin >> this->staffWorkYears;
    while (staffWorkYears < 0 || staffWorkYears > 40) {
        cout << "输入格式错误，请重新输入！" << endl;
        cin.clear();
        cin >> this->staffWorkYears;
    }
}

// 获取工龄
int BaseStaff::getWorkYears() const {
    return this->staffWorkYears;
}

// 设置工资
void BaseStaff::setStaffSalary() {
    cout << "-->工资:";
    cin >> this->staffSalary;
}

// 获取工资
int BaseStaff::getStaffSalary() const {
    return this->staffSalary;
}

// 设置等级
void BaseStaff::setStaffGrade() {
    cout << "-->等级:";
    cin >> this->staffGrade;
}

// 获取等级信息
int BaseStaff::getStaffGrade() const {
    return this->staffGrade;
}

//重载BaseStaff类的输出 <<
void operator<<(ostream &out, BaseStaff *baseStaffPtr) {
    baseStaffPtr->showInfos();
}
