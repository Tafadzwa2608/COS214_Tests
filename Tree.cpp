#include "Tree.h"

Tree::Tree(const std::string &name, const std::string &maintenanceType, double height, double price)
    : NurseryPlant(name, maintenanceType, price), height(height) {}
double Tree::getHeight() const
{
    return height;
}
