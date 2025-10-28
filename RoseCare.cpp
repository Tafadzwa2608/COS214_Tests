#include "RoseCare.h"
#include "ConcreteState.h"
void RoseCare::performCare(NurseryPlant &plant)
{
    std::cout << "Performing care for Rose\n";
    std::cout << "- Water: daily (lightly)\n";
    std::cout << "- Sunlight: 5–6 hours/day\n";
    std::cout << "- Fertilizer: rose mix every 10 days\n";

    if (plant.getStateName() == "Seedling")
    {
        plant.setState(new SproutState());
    }
    else
    {
        plant.setState(new MatureState());
    }

    std::cout << "- Rose state updated to: " << plant.getStateName() << "\n\n";
}