/**
 * @file Nurse.h
 * @brief Declaration of the Nurse class, derived from Staff.
 */

#ifndef NURSE_H
#define NURSE_H

#include "Staff.h"
#include "HighMaintenancePlantFactory.h"
#include <iostream>

/**
 * @class Nurse
 * @brief Represents a nurse who tends to the plants' health.
 */
class Nurse : public Staff
{
public:
    /**
     * @brief Constructs a Nurse with access to the inventory.
     * @param inventory Pointer to the Inventory object.
     * @param name Name of the nurse.
     */
    Nurse(Inventory *inventory, const std::string &name);

    /**
     * @brief Default destructor.
     */
    ~Nurse() override = default;

    /**
     * @brief Provides plant care specific to health maintenance.
     */
    void tendToPlants(NurseryPlant *plant);

    void update(NurseryPlant *plant)override;
};

#endif // NURSE_H