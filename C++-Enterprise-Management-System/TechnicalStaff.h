#ifndef ENTERPRISE_MANAGEMENT_SYSTEM_TECHNICALSTAFF_H
#define ENTERPRISE_MANAGEMENT_SYSTEM_TECHNICALSTAFF_H

#endif //ENTERPRISE_MANAGEMENT_SYSTEM_TECHNICALSTAFF_H
#pragma once

#include "BaseStaff.h"

class TechnicalStaff : public BaseStaff {
public:
    string technology;
    string devote;

    TechnicalStaff();

    ~TechnicalStaff();

    void setTechnicalField();

    string getTechnicalField() const;

    void setTechnicaDevote();

    string gettechnicaDevote() const;

    void showInfos();
};
