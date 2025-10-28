#include "HighMaintenanceTreeCare.h"

    void HighMaintenanceTreeCare:: performCare(NurseryPlant& plant) {
         std::cout << "Performing high-maintenance care for tree: "
                  << plant.getName() << std::endl;
        std::cout << " - Deep watering twice weekly\n - Prune monthly\n - Soil nutrient check\n";
    }

    HighMaintenanceTreeCare::~HighMaintenanceTreeCare() {}
