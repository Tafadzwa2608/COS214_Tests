/**
 * @file Crate.h
 * @author Tafadzwa Musiiwa
 * @brief Concrete class representing a wooden crate container.
 */

#ifndef CRATE_H
#define CRATE_H

#include "Container.h"
#include <string>

/**
 * @class Crate
 * @brief Represents a wooden crate used for holding plants.
 */
class Crate : public Container
{
private:
    std::string material;

public:
    /**
     * @brief Constructs a Crate with a given material type.
     * @param material The type of material (e.g., "wood", "plastic").
     */
    Crate(const std::string& material);

    /**
     * @brief Destructor.
     */
    ~Crate() {}
    /**
     * @brief Display the information about the crate (the material used to create the crate).
     */
    void display() const override;

    /**
     * @brief getter for the crate type.
     */
    std::string getType() const override;
};

#endif 
