/**
 * @file LowMaintenancePlantFactory.h
 * @author Tafadzwa Musiiwa
 * @brief Factory for creating low-maintenance plant types.
 */

#ifndef LOWMAINTENANCEPLANTFACTORY_H
#define LOWMAINTENANCEPLANTFACTORY_H

#include "PlantFactory.h"
#include "FloweringPlant.h"
#include "Tree.h"

/**
 * @class LowMaintenancePlantFactory
 * @brief Concrete factory that creates low-maintenance plants.
 *
 * Implements creation methods for plants that require minimal upkeep.
 */
class LowMaintenancePlantFactory : public PlantFactory
{
public:
    /**
     * @brief Creates a low-maintenance flowering plant.
     * @return Pointer to a new low-maintenance FloweringPlant.
     */
    FloweringPlant *createFloweringPlant(double price, std::string color);

    /**
     * @brief Creates a low-maintenance tree.
     * @return Pointer to a new low-maintenance Tree.
     */
    Tree *createTree(double height, double price) override;
};

#endif // LOWMAINTENANCEPLANTFACTORY_H
