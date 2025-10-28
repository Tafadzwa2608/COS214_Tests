/**
 * @file PlantExpert.h
 * @brief Declaration of the PlantExpert class, derived from Staff.
 */

#ifndef PLANTEXPERT_H
#define PLANTEXPERT_H

#include "Staff.h"
#include <iostream>

/**
 * @class PlantExpert
 * @brief Provides specialized advice on plant care and species management.
 */
class PlantExpert : public Staff
{
public:
    /**
     * @brief Constructs a PlantExpert with access to the inventory.
     * @param inventory Pointer to the Inventory object.
     * @param name Name of the plant expert.
     */
    PlantExpert(Inventory *inventory, const std::string &name);

    /**
     * @brief Default destructor.
     */
    ~PlantExpert() override = default;

    /**
     * @brief Offers advice on plant health or care.
     */
    void giveAdvice();

    void careForSpecificPlant(NurseryPlant &plant, CareStrategy *specificStrategy);
};

#endif // PLANTEXPERT_H
