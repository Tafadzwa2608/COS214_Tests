#ifndef ALOECARE_H
#define ALOECARE_H

#include "CareStrategy.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Concrete strategy for Aloe plant care
 *
 * Implements the specific care routine for Aloe plants including
 * watering schedule, sunlight requirements, and fertilization.
 */
class AloeCare : public CareStrategy
{
public:
    /**
     * @brief Perform Aloe-specific care routine
     * @param plant Reference to the NurseryPlant to care for
     */
    void performCare(NurseryPlant &plant) override;
};

#endif