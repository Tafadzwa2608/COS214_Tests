#ifndef LOWMAINTENANCEPLANTCARE_H
#define LOWMAINTENANCEPLANTCARE_H

#include "CareStrategy.h"

class LowMaintenancePlantCare : public CareStrategy {
public:
    void performCare(NurseryPlant& plant) override;
    virtual ~LowMaintenancePlantCare();
};



#endif
