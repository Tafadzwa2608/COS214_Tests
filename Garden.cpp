#include "Garden.h"

Garden::~Garden()
{

    plants.clear();
}

void Garden::addPlant(NurseryPlant *plant, Container *container)
{
    if (plant)
    {
        plants.push_back({plant, container});
        std::cout << "Plant added to the garden: " << plant->getName();
        if (container)
            std::cout << " in a " << container->getType();
        std::cout << std::endl;
    }
}

void Garden::removePlant(int index)
{
    if (index < 0 || index >= plants.size())
    {
        std::cout << "Invalid index. Cannot remove plant." << std::endl;
        return;
    }

    delete plants[index].plant;
    delete plants[index].container;
    plants.erase(plants.begin() + index);
    std::cout << "Plant removed from the garden." << std::endl;
}

void Garden::displayPlants() const
{
    if (plants.empty())
    {
        std::cout << "The garden is empty." << std::endl;
        return;
    }

    std::cout << "Plants in the garden:" << std::endl;
    for (size_t i = 0; i < plants.size(); ++i)
    {
        std::cout << i << ": ";
        plants[i].plant->displayInfo();
        if (plants[i].container)
        {
            plants[i].container->display();
        }
    }
}

int Garden::getPlantCount() const
{
    return plants.size();
}
