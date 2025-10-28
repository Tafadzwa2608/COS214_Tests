#ifndef HIGHMAINTENANCETREECARE_H
#define HIGHMAINTENANCETREECARE_H

#include "CareStrategy.h"

class HighMaintenanceTreeCare : public CareStrategy {
public:
    void performCare(NurseryPlant& plant) override;
    virtual ~HighMaintenanceTreeCare();
};

#endif
