
#include "CherryBlossom.h"
#include <iostream>


CherryBlossom::CherryBlossom(double price)
    : FloweringPlant("Cherry Blossom", "High Maintenance", "Pink", price) {
    std::cout << "🌸 Cherry Blossom planted.\n";
} //Assumption: I assumed all CherryBlossoms are pink

void CherryBlossom::displayInfo() const {
    std::cout << "Cherry Blossom (" << color << ") - " << maintenanceType << " Flowering Plant.\n";
}
