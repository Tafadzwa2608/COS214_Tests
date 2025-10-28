#include "CherryCare.h"
#include "ConcreteState.h"

void CherryBlossomCare::performCare(NurseryPlant &plant)
{
    std::cout << "Performing care for Cherry Blossom\n";
    std::cout << "- Water: every 3 days\n";
    std::cout << "- Sunlight: bright but partial shade\n";
    std::cout << "- Fertilizer: early spring & mid-summer\n";
    if (plant.getStateName() == "Seedling")
    {
        plant.setState(new SproutState());
    }
    else
    {
        plant.setState(new MatureState());
    }
    std::cout << "- Cherry Blossom state updated to: " << plant.getStateName() << "\n\n";
}