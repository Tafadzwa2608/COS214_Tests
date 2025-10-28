
#ifndef ROSECARE_H
#define ROSECARE_H

#include "CareStrategy.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Concrete strategy for Rose plant care
 * 
 * Implements the specific care routine for Rose plants including
 * frequent watering, sunlight requirements, and specialized fertilizer.
 */
class RoseCare : public CareStrategy {
public:
    /**
     * @brief Perform Rose-specific care routine
     * @param plant Reference to the NurseryPlant to care for
     */
    void performCare(NurseryPlant& plant) override;
};

#endif