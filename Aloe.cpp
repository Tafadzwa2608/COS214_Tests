#include "Aloe.h"
#include <iostream>

Aloe::Aloe(double height, double price)
    : Tree("Aloe", "Low Maintenance", height, price)
{
    std::cout << "🌿 Aloe planted.\n";
}

void Aloe::displayInfo() const
{
    std::cout << "Aloe - " << maintenanceType << " Tree, Height: " << height << " m.\n";
}