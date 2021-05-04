#include "ManagementStaff.h"

ManagementStaff::ManagementStaff() {
    this->staffDutyType = 3;
    setStaffNumber();
    setStaffName();
    setStaffSex();
    setWorkYears();
    setStaffSalary();
    setPlanningSuccessRate();
    setTargeAchievementRate();
    setStaffManagementRate();
}

ManagementStaff::~ManagementStaff() {
}

void ManagementStaff::setPlanningSuccessRate() {
    cout << "策划成功率:";
    cin >> this->planningSuccessRate;
}

int ManagementStaff::getPlanningSuccessRate() const {
    return this->planningSuccessRate;
}

void ManagementStaff::setTargeAchievementRate() {
    cout << "企划目标达成率:";
    cin >> this->targeAchievementRate;
}

int ManagementStaff::getTargeAchievementRate() const {
    return this->targeAchievementRate;
}

void ManagementStaff::setStaffManagementRate() {
    cout << "员工管理率:";
    cin >> this->staffManagementRate;
}

int ManagementStaff::getStaffManagementRate() const {
    return this->staffManagementRate;
}

void ManagementStaff::showInfos() {
    cout << "\n\"----------------管理类人员信息表------------------------" << endl;
    cout << "工号:" << getStaffNumber() << endl;
    cout << "姓名:" << getStaffName() << endl;
    cout << "性别:" << getStaffSex() << endl;
    cout << "工龄" << getWorkYears() << endl;
    cout << "工资" << getStaffSalary() << endl;
    cout << "等级:" << getStaffGrade() << endl;
    cout << "策划成功率:" << getPlanningSuccessRate() << endl;
    cout << "企划目标达成率:" << getTargeAchievementRate() << endl;
    cout << "员工管理率:" << getStaffManagementRate() << endl;
    cout << "--------------------------------------------------------\n" << endl;
}
