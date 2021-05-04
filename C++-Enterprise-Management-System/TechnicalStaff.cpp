#include "TechnicalStaff.h"


TechnicalStaff::TechnicalStaff() {
    this->staffDutyType = 1;
    setStaffNumber();
    setStaffName();
    setStaffSex();
    setWorkYears();
    setStaffSalary();
    setStaffGrade();
    setTechnicalField();
    setTechnicaDevote();
}

void TechnicalStaff::setTechnicalField() {
    cout << "技术领域:";
    cin >> this->technology;
}

string TechnicalStaff::getTechnicalField() const {
    return this->technology;
}

void TechnicalStaff::setTechnicaDevote() {
    cout << "技术贡献:";
    cin >> this->devote;
}

string TechnicalStaff::gettechnicaDevote() const {
    return this->devote;
}

TechnicalStaff::~TechnicalStaff() {
}

void TechnicalStaff::showInfos() {
    cout << "\n\"----------------技术类人员信息表------------------------" << endl;
    cout << "工号:" << getStaffNumber() << endl;
    cout << "姓名:" << getStaffName() << endl;
    cout << "性别:" << getStaffSex() << endl;
    cout << "工龄:" << getWorkYears() << endl;
    cout << "工资:" << getStaffSalary() << endl;
    cout << "等级:" << getStaffGrade() << endl;
    cout << "技术领域:" << getTechnicalField() << endl;
    cout << "技术贡献:" << gettechnicaDevote() << endl;
    cout << "-------------------------------------------------------\n" << endl;
}
