#include "Nurse.h"
#include "WaterPlantCommand.h"
Nurse::Nurse(Inventory *inventory, const std::string &name) : Staff(inventory, name, new HighMaintenancePlantCare())
// Nurses default to high-maintenance care
{
}

void Nurse::tendToPlants(NurseryPlant *plant)
{
    std::cout << getName() << " is tending to plant health with specialized care.\n";
    perform(new WaterPlantCommand(plant->getName()));
    strategy->performCare(*plant);
}

void Nurse::update(NurseryPlant *plant)
{
    if (plant->getStateName() == "Wilting" || plant->getStateName() == "Sprout")
    {
        tendToPlants(plant);
    }
}