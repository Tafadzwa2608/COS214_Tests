#include "WaterPlantCommand.h"

WaterPlantCommand::WaterPlantCommand(std::string p) {
    plantName = p;
}

void WaterPlantCommand::execute() {
    std::cout << "Watering " << plantName << "...\n";
}

