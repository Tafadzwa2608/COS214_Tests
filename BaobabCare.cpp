#include "BaobabCare.h"
#include "ConcreteState.h"

void BaobabCare::performCare(NurseryPlant &plant)
{
    std::cout << " Special care for Baobab\n";
    std::cout << "- Water: once every 2 weeks\n";
    std::cout << "- Sunlight: full exposure\n";
    std::cout << "- Fertilizer: once every 3 months\n";
    if (plant.getStateName() == "Seedling")
    {
        plant.setState(new SproutState());
    }
    else
    {
        plant.setState(new MatureState());
    }
    std::cout << "- Baobab state updated to: " << plant.getStateName() << "\n\n";
}