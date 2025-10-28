#include "HighMaintenancePlantFactory.h"
#include "Rose.h"
#include "CherryBlossom.h"
#include "Aloe.h"
#include "Baobab.h"
#include <iostream>

FloweringPlant *HighMaintenancePlantFactory::createFloweringPlant(double price, std::string color)
{
    std::cout << "Creating a high maintenance flowing plant (CherryBlossom)" << std::endl;

    return new CherryBlossom(price);
}

Tree *HighMaintenancePlantFactory::createTree(double height, double price)
{
    std::cout << "Creating a high maintenance tree (Baobab)" << std::endl;

    return new Baobab(height, price);
}