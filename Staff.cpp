
#include "Staff.h"
#include "NurseryPlant.h"
#include "Inventory.h"
#include <iostream>

Staff::Staff(Inventory *inventory, std::string n, CareStrategy *s) : inventory(inventory), name(n), strategy(s)
{
}

Staff::~Staff()
{
    delete strategy;
}
void Staff::setStrategy(CareStrategy *s)
{
    if (strategy)
    {
        delete strategy;
    }
    strategy = s;
}

std::string Staff::getName() const
{
    return name;
}
void Staff::careForPlant(NurseryPlant &plant)
{
    std::cout << name << " is caring for " << plant.getName() << "...\n";
    plant.attach(this);
    if (strategy)
        strategy->performCare(plant);
    else
        std::cout << "No care strategy set for " << name << "!\n";
}
void Staff::perform(Command *cmd)
{
    std::cout << name << " executing command...\n";
    cmd->execute();
}