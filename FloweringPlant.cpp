#include "FloweringPlant.h"
FloweringPlant::FloweringPlant(const std::string& name, const std::string& maintenanceType, const std::string& color, double price)
        : NurseryPlant(name, maintenanceType, price), color(color) {}
std::string FloweringPlant::getColor() const {
    return color;
}
