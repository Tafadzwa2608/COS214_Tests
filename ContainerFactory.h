/**
 * @file ContainerFactory.h
 * @author Tafadzwa Musiiwa
 * @brief Abstract factory for creating containers for plants.
 */

#ifndef CONTAINERFACTORY_H
#define CONTAINERFACTORY_H

#include "Container.h"

/**
 * @class ContainerFactory
 * @brief Abstract class defining the interface for container creation.
 *
 * This factory is responsible for producing different types of plant containers,
 * such as crates, pots, etc.
 */
class ContainerFactory
{
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~ContainerFactory() {}

    /**
     * @brief Creates a container.
     * @return Pointer to a new Container object.
     */
    virtual Container* createContainer(std::string material) = 0;
};

#endif 
