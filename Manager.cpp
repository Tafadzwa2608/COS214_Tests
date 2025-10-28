#include "Manager.h"
#include "Issue.h"
#include <iostream>

Manager::Manager(Inventory *inventory, const std::string &name)
    : Staff(inventory, name, new HighMaintenancePlantCare()) // Managers might handle complex cases
{
    staffMembers = {"Alice (Nurse)", "Bob (Cashier)", "Dr. Green (Expert)"};
}

void Manager::handleDispute(const std::string &customerName, const std::string &issue)
{
    std::cout << "Manager " << getName() << " handling dispute from " << customerName << std::endl;
    std::cout << "Issue: " << issue << std::endl;
    std::cout << " Dispute resolved by management authority.\n"
              << std::endl;
}

void Manager::reviewStaffPerformance()
{
    std::cout << "Manager " << getName() << " conducting staff performance review:" << std::endl;
    for (const auto &staff : staffMembers)
    {
        std::cout << " - Reviewing: " << staff << " - Performance: Satisfactory" << std::endl;
    }
    std::cout << " Performance review completed.\n"
              << std::endl;
}

void Manager::update(NurseryPlant *plant)
{
    std::cout << getName() << " overseeing: " << plant->getName()
              << " is now " << plant->getStateName() << ".\n";

    if (plant->getStateName() == "Mature")
    {
        std::cout << "Manager: verifying plant quality before it's added to inventory.\n";
        std::cout << "Quality check passed  — plant ready for sale approval.\n";
    }

    if (plant->getStateName() == "Wilting")
    {
        std::cout << "Manager: notifying Nurse to attempt recovery.\n";
    }
}