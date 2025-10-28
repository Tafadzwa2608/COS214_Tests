#include "Baobab.h"
#include <iostream>

Baobab::Baobab(double height, double price)
    : Tree("Baobab", "High Maintenance", height, price)
{
    std::cout << "🌳 Baobab planted.\n";
}

void Baobab::displayInfo() const
{
    std::cout << "Baobab - " << maintenanceType << " Tree, Height: " << height << " m.\n";
}