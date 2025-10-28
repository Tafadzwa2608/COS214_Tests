#include "Rose.h"
#include <iostream>

Rose::Rose(const std::string& color, double price) : FloweringPlant("Rose","High Maintenance",color, price){
      std::cout << "🌹 A " << color << " Rose has been planted.\n";
}

void Rose::displayInfo() const {
    std::cout << "Rose (" << color << ") - " << maintenanceType << " Flowering Plant.\n";
    std::cout << "🌹 Special care instructions for Rose applied.\n";
}