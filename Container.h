/**
 * @file Container.h
 * @author Tafadzwa Musiiwa
 * @brief Abstract class representing a container for plants.
 */

#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>

/**
 * @class Container
 * @brief Abstract representation of a plant container.
 *
 * Serves as a base for specific container types like Crate.
 */
class Container
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~Container() {}

     /**
     * @brief default constructor.
     */
    Container() = default;

     /**
     * @brief Display information about the container.
     * Must be implemented by derived classes.
     */
    virtual void display() const = 0;

      /**
     * @brief getter for container type (name).
     */
    virtual std::string getType() const = 0;
};

#endif
