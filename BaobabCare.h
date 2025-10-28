#ifndef BAOBABCARE_H
#define BAOBABCARE_H

#include "CareStrategy.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Concrete strategy for Baobab tree care
 *
 * Implements the specific care routine for Baobab trees including
 * specialized watering, sunlight, and fertilization requirements.
 */
class BaobabCare : public CareStrategy
{
public:
    /**
     * @brief Perform Baobab-specific care routine
     * @param plant Reference to the NurseryPlant to care for
     */
    void performCare(NurseryPlant &plant) override;
};

#endif