

#include <iostream>
#include <algorithm>
#include "NurseryPlant.h"
#include "ConcreteState.h"
#include "Staff.h"
using namespace std;

NurseryPlant::NurseryPlant(const string &name, const string &maintenanceType, double price)
    : Order(price), name(name), maintenanceType(maintenanceType)
{
    this->currentState = new SeedlingState();
}

NurseryPlant::~NurseryPlant()
{
    delete currentState;
}

string NurseryPlant::getName() const
{
    return name;
}

string NurseryPlant::getMaintenanceType() const
{
    return maintenanceType;
}

double NurseryPlant::getTotal()
{
    return price + (price * taxRate);
}

void NurseryPlant::displayDetails()
{
    cout << "Nursery Plant Order: " << orderID
         << " | Name: " << name
         << " | Maintenance Type: " << maintenanceType
         << " | Base Price: " << price
         << " | Total (with tax): " << getTotal() << endl;
}

void NurseryPlant::calculateTax()
{
    cout << "Tax for " << orderID << ": " << price * taxRate << endl;
}

Order *NurseryPlant::clone() const
{
    return new NurseryPlant(*this);
}

void NurseryPlant::showStaff() const
{
    std::cout << "Staff caring for " << name << ": ";
    for (auto s : observers)
        std::cout << (dynamic_cast<Staff *>(s))->getName() << " ";
    std::cout << "\n";
}

void NurseryPlant::displayInfo() const
{
    cout << "Plant Name: " << name
         << "Plant State: " << getStateName()
         << ", Maintenance Type: " << maintenanceType
         << ", Price: " << price << endl;
}

void NurseryPlant::setState(State *newState)
{
    delete currentState;
    currentState = newState;
    notify();
}

void NurseryPlant::startGrowing()
{
    while (this->getStateName() != "Mature")
    {
        currentState->handleAction(this);
    }
}

std::string NurseryPlant::getStateName() const
{
    return currentState->getStateName();
}

void NurseryPlant::attach(Observer *observer)
{
    observers.push_back(observer);
}

void NurseryPlant::detach(Observer *observer)
{
    auto it = std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end())
    {
        observers.erase(it);
    }
}

void NurseryPlant::notify()
{
    for (Observer *obs : observers)
    {
        obs->update(this);
    }
}