/**
 * @file Tree.h
 * @author Tafadzwa Musiiwa
 * @brief Abstract class representing trees.
 */

#ifndef TREE_H
#define TREE_H

#include "NurseryPlant.h"

/**
 * @class Tree
 * @brief Abstract class for tree-type plants.
 *
 * Serves as a base for specific trees such as Aloe and Baobab.
 */
class Tree : public NurseryPlant
{
protected:
   double height;
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~Tree() {}

    /**
     * @brief Constructor.
     */
    Tree(const std::string& name, const std::string& maintenanceType, double height, double);

    /**
     * @brief getter of the height of a tree.
     */
    double getHeight() const;
};

#endif
