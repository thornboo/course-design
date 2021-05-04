#ifndef ENTERPRISE_MANAGEMENT_SYSTEM_MARKETINGSTAFF_H
#define ENTERPRISE_MANAGEMENT_SYSTEM_MARKETINGSTAFF_H

#endif //ENTERPRISE_MANAGEMENT_SYSTEM_MARKETINGSTAFF_H
#pragma once

#include "BaseStaff.h"

class MarketingStaff : public BaseStaff {
public:
    int totalAnnualSales;
    int customerReception;

    MarketingStaff();

    ~MarketingStaff();

    void showInfos();

    void setTotalAnnualSales(); //年销售总额

    int getTotalAnnualSales() const;

    void setCustomerReception(); //客户接待量

    int getCustomerReception() const;
};

