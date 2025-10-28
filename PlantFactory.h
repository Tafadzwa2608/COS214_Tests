/**
 * @file PlantFactory.h
 * @author Tafadzwa Musiiwa
 * @brief Abstract interface for creating different types of plants
 */

#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "FloweringPlant.h"
#include "Tree.h"

/**
 * @class PlantFactory
 * @brief Abstract factory for creating plant objects.
 *
 * Defines the interface for factories that can create different categories of plants,
 * such as flowering plants and trees
 */

class PlantFactory
{
public:
  /**
   * @brief Default constructor
   */
  PlantFactory() = default;
  /**
   * @brief Virtual destructor
   */
  virtual ~PlantFactory() {};

  /**
   * @brief Creates a FloweringPlant object.
   * @return Pointer to a new FloweringPlant.
   */
  virtual FloweringPlant *createFloweringPlant(double price, std::string color) = 0;

  /**
   * @brief Creates a Tree object.
   * @return Pointer to a new Tree.
   */
  virtual Tree *createTree(double height, double price) = 0;
};
#endif