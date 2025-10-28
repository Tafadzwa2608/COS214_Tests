/**
 * @file CrateFactory.h
 * @author Tafadzwa Musiiwa
 * @brief Factory that produces crate-type containers.
 */

#ifndef CRATEFACTORY_H
#define CRATEFACTORY_H

#include "ContainerFactory.h"

/**
 * @class CrateFactory
 * @brief Concrete factory that creates crate containers.
 *
 * Implements the factory method for creating crate-style plant containers.
 */
class CrateFactory : public ContainerFactory
{
public:
    /**
     * @brief Creates a crate container.
     * @return Pointer to a new Crate object.
     */
    Container* createContainer(std::string material);
};

#endif 
