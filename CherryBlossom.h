/**
 * @file CherryBlossom.h
 * @author Tafadzwa Musiiwa
 * @brief Concrete class representing a Cherry Blossom tree.
 */

#ifndef CHERRYBLOSSOM_H
#define CHERRYBLOSSOM_H

#include "FloweringPlant.h"
#include <string>

/**
 * @class CherryBlossom
 * @brief Represents a cherry blossom, a type of flowering plant.
 */
class CherryBlossom : public FloweringPlant
{


public:
    /**
     * @brief Constructs a CherryBlossom with a given blooming season.
     * 
     */
    CherryBlossom(double price);

    /**
     * @brief Destructor.
     */
    ~CherryBlossom() {}
    /**
     * @brief Display information about the CherryBlossom plant.
     */
    void displayInfo() const override;
};

#endif
