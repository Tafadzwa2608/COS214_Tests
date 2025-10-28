#include "AloeCare.h"
#include "ConcreteState.h"
void AloeCare::performCare(NurseryPlant &plant)
{
    std::cout << "Performing care for Aloe\n";
    std::cout << "- Water: once every 10 days (avoid overwatering)\n";
    std::cout << "- Sunlight: indirect light preferred\n";
    std::cout << "- Fertilizer: every 2 months\n";

    if (plant.getStateName() == "Seedling")
    {
        plant.setState(new SproutState());
    }
    else
    {
        plant.setState(new MatureState());
    }

    std::cout << "- Aloe state updated to: " << plant.getStateName() << "\n\n";
}