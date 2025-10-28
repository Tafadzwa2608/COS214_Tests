#include "LowMaintenancePlantCare.h"

    void LowMaintenancePlantCare:: performCare(NurseryPlant& plant) {
        std::cout << "Performing low-maintenance care for plant: "
                  << plant.getName() << std::endl;
        std::cout << " - Water once a week\n - Occasional fertilizer\n - Partial sunlight\n";
    }


    LowMaintenancePlantCare::~LowMaintenancePlantCare() {}