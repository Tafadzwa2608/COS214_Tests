/**
 * @file Rose.h
 * @author Tafadzwa Musiiwa
 * @brief Concrete class representing a Rose plant.
 */

#ifndef ROSE_H
#define ROSE_H

#include "FloweringPlant.h"
#include <string>

/**
 * @class Rose
 * @brief Represents a rose, a type of flowering plant.
 */
class Rose : public FloweringPlant
{


public:
    /**
     * @brief Constructs a Rose with a given colour.
     * 
     */
    Rose(const std::string& color, double price);

    /**
     * @brief Destructor.
     */
    ~Rose() {}
    /**
     * @brief Display information about a Rose.
     */
    void displayInfo() const ;
};

#endif
