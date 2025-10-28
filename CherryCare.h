#ifndef CHERRYBLOSSOMCARE_H
#define CHERRYBLOSSOMCARE_H

#include "CareStrategy.h"
#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Concrete strategy for Cherry Blossom care
 * 
 * Implements the specific care routine for Cherry Blossom plants
 * including seasonal care requirements and specific conditions.
 */
class CherryBlossomCare : public CareStrategy {
public:
    /**
     * @brief Perform Cherry Blossom-specific care routine
     * @param plant Reference to the NurseryPlant to care for
     */
    void performCare(NurseryPlant& plant) override;
};

#endif

