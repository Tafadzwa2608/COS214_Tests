#ifndef LOWMAINTENANCETREECARE_H
#define LOWMAINTENANCETREECARE_H

#include "CareStrategy.h"

class LowMaintenanceTreeCare : public CareStrategy
{
public:
    void performCare(NurseryPlant &plant) override;
    virtual ~LowMaintenanceTreeCare();
};

#endif
