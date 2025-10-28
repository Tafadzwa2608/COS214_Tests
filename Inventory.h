/**
 * @file Inventory.h
 * @brief Header file for the Inventory class, managing plant stock.
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>
#include <map>
#include "NurseryPlant.h"

/**
 * @brief Manages the inventory of nursery plants.
 *
 * The Inventory class uses a map to store plants by name, allowing addition, removal, and display of stock.
 */
class Inventory {
private:
    std::map<std::string, std::vector<NurseryPlant*>> itemStock; /**< Map of plant names to lists of plant pointers. */

public:
    /**
     * @brief Default constructor.
     */
    Inventory() = default;

    /**
     * @brief Default destructor.
     */
    ~Inventory() = default;

    /**
     * @brief Adds a plant to the inventory.
     * @param itemName The name of the plant type.
     * @param plant Pointer to the NurseryPlant to add.
     */
    void addPlant(const std::string& itemName, NurseryPlant* plant);

    /**
     * @brief Removes a plant from the inventory.
     * @param itemName The name of the plant type to remove from.
     */
    void removePlant(const std::string& itemName);

    /**
     * @brief Displays the current inventory.
     */
    void displayInventory() const;
};

#endif
