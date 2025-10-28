#ifndef CARESTRATEGY_H
#define CARESTRATEGY_H

#include <iostream>
#include "NurseryPlant.h"

/**
 * @brief Strategy interface for plant care behaviors
 *
 * Provides a unified interface for care routines based on maintenance level.
 */
class NurseryPlant;
class CareStrategy
{
public:
    /**
     * @brief Perform care routine for a specific plant
     * @param plant Reference to the NurseryPlant to care for
     */
    virtual void performCare(NurseryPlant &plant) = 0;

    virtual ~CareStrategy();
};

#endif
