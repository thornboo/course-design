#include "MarketingStaff.h"

MarketingStaff::~MarketingStaff() {
}

MarketingStaff::MarketingStaff() {
    this->staffDutyType = 2;
    setStaffNumber();
    setStaffName();
    setStaffSex();
    setWorkYears();
    setStaffSalary();
    setStaffGrade();
    setTotalAnnualSales();
    setCustomerReception();
}

void MarketingStaff::setTotalAnnualSales() {
    cout << "年销售总额:";
    cin >> this->totalAnnualSales;
}

int MarketingStaff::getTotalAnnualSales() const {
    return this->totalAnnualSales;
}

void MarketingStaff::setCustomerReception() {
    cout << "客户接待量:";
    cin >> this->customerReception;
}

int MarketingStaff::getCustomerReception() const {
    return this->customerReception;
}


void MarketingStaff::showInfos() {
    cout << "\n\"----------------营销类人员信息表------------------------" << endl;
    cout << "工号:" << getStaffNumber() << endl;
    cout << "姓名:" << getStaffName() << endl;
    cout << "性别:" << getStaffSex() << endl;
    cout << "工龄:" << getWorkYears() << endl;
    cout << "工资:" << getStaffSalary() << endl;
    cout << "等级:" << getStaffGrade() << endl;
    cout << "年销售总额:" << getTotalAnnualSales() << endl;
    cout << "客户接待量:" << getCustomerReception() << endl;
    cout << "--------------------------------------------------------\n" << endl;
}
