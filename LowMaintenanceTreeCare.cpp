#include "LowMaintenanceTreeCare.h"

    void LowMaintenanceTreeCare:: performCare(NurseryPlant& plant) {
        std::cout << "Performing low-maintenance care for tree: "
                  << plant.getName() << std::endl;
        std::cout << " - Deep watering every 2 weeks\n - Minimal pruning\n";
    }

    LowMaintenanceTreeCare::~LowMaintenanceTreeCare() {}