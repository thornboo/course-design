#include "OperatorStaff.h"

OperatorStaff::OperatorStaff() {
    this->staffDutyType = 4;
    setStaffNumber();
    setStaffName();
    setStaffSex();
    setWorkYears();
    setStaffSalary();
    setStaffGrade();
    setResolveFailureRate();
    setWorkEfficiency();
    setProjectCompletion();
}

OperatorStaff::~OperatorStaff() {
}

void OperatorStaff::setResolveFailureRate() {
    cout << "故障解决率:";
    cin >> this->resolveFailureRate;
}

int OperatorStaff::getResolveFailureRate() const {
    return this->resolveFailureRate;
}

void OperatorStaff::setWorkEfficiency() {
    cout << "工作效率:";
    cin >> this->workEfficiency;
}

int OperatorStaff::getWorkEfficiency() const {
    return this->workEfficiency;
}

void OperatorStaff::setProjectCompletion() {
    cout << "操作项目完成数:";
    cin >> this->projectCompletion;
}

int OperatorStaff::getProjectCompletion() const {
    return this->projectCompletion;
}

void OperatorStaff::showInfos() {
    cout << "\n\"----------------操作类人员信息表------------------------" << endl;
    cout << "工号:" << getStaffNumber() << endl;
    cout << "姓名:" << getStaffName() << endl;
    cout << "性别:" << getStaffSex() << endl;
    cout << "工龄" << getWorkYears() << endl;
    cout << "工资" << getStaffSalary() << endl;
    cout << "等级:" << getStaffGrade() << endl;
    cout << "故障解决率:" << getResolveFailureRate() << endl;
    cout << "工作效率:" << getWorkEfficiency() << endl;
    cout << "操作项目完成数:" << getProjectCompletion() << endl;
    cout << "--------------------------------------------------------\n" << endl;
}
