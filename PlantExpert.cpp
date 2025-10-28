#include "PlantExpert.h"

PlantExpert::PlantExpert(Inventory *inventory, const std::string &name) : Staff(inventory, name, nullptr)
// Experts don't have a default - they choose based on plant
{
}

void PlantExpert::giveAdvice()
{

    std::cout << getName() << " is providing expert plant care advice.\n";
}

void PlantExpert::careForSpecificPlant(NurseryPlant &plant, CareStrategy *specificStrategy)
{
    // Experts can dynamically choose the right strategy, since they are very knowledgeable

    setStrategy(specificStrategy);
    careForPlant(plant);
}