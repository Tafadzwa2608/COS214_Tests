#include "HighMaintenancePlantCare.h"

    void HighMaintenancePlantCare:: performCare(NurseryPlant& plant) {
           std::cout << "Performing high-maintenance care for plant: "
                  << plant.getName() << std::endl;
        std::cout << " - Water daily\n - Fertilize weekly\n - Full sunlight\n";
    }

    HighMaintenancePlantCare::~HighMaintenancePlantCare() {}
