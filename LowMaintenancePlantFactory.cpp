#include "LowMaintenancePlantFactory.h"
#include "Aloe.h"
#include "Baobab.h"
#include "Rose.h"
#include "CherryBlossom.h"
#include <iostream>

FloweringPlant *LowMaintenancePlantFactory::createFloweringPlant(double price, std::string color)
{
    std::cout << "Creating a low maintenance flowering plant (Rose)" << std::endl;

    return new Rose(color, price);
}

Tree *LowMaintenancePlantFactory::createTree(double height, double price)
{
    std::cout << "Creating a low maintenance tree (Aloe)" << std::endl;

    return new Aloe(height, price);
}