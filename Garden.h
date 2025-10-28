/**
 * @file Garden.h
 * @author Tafadzwa Musiiwa
 * @brief Class Representing the Garden.
 */

#ifndef GARDEN_H
#define GARDEN_H

#include "Container.h"
#include "NurseryPlant.h"
#include <vector>
#include <iostream>

/**
 * @class Garden
 * @brief Represents a collection of plants in the nursery.
 *
 * The Garden class allows adding, removing, and displaying plants.
 * It manages the memory of the plants added to it.
 */
class Garden {
private:
      struct PlantEntry {
        NurseryPlant* plant;
        Container* container;
    };
    std::vector<PlantEntry> plants; /**< Container for storing pointers to plants */

public:
    /**
     * @brief Default constructor.
     */
    Garden() = default;

    /**
     * @brief Destructor. Deletes all plants in the garden to prevent memory leaks.
     */
    ~Garden();

    /**
     * @brief Adds a plant to the garden.
     * @param plant Pointer to a NurseryPlant object to add.
     *              The Garden takes ownership of the plant.
     * @param container Pointer to a Container object to add.
     *              
     */
    void addPlant(NurseryPlant* plant, Container* container);

    /**
     * @brief Removes a plant from the garden by index.
     * @param index The index of the plant to remove.
     *              If index is invalid, no removal occurs.
     */
    void removePlant(int index);

    /**
     * @brief Displays information about all plants in the garden.
     */
    void displayPlants() const;

    /**
     * @brief Returns the total number of plants in the garden.
     * @return Number of plants.
     */
    int getPlantCount() const;
};

#endif
