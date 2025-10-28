#ifndef HIGHMAINTENANCEPLANTCARE_H
#define HIGHMAINTENANCEPLANTCARE_H

#include "CareStrategy.h"

class HighMaintenancePlantCare : public CareStrategy {
public:
    void performCare(NurseryPlant& plant) override;
    virtual ~HighMaintenancePlantCare();
};

#endif
