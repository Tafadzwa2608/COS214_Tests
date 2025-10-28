#include "Cashier.h"

Cashier::Cashier(Inventory *inventory, const std::string &name)
    : Staff(inventory, name, new LowMaintenancePlantCare())
{
    // Cashiers handle simple plant care
}

void Cashier::processSale(const std::string &plantName, double amount)
{
    if (!paymentStrategy)
    {
        std::cout << "No payment method selected!\n";
        return;
    }

    std::cout << "Processing sale for " << plantName << " - Amount: $" << amount << "\n";

    if (paymentStrategy->processPayment(amount))
    {
        std::cout << "Payment successful using " << paymentStrategy->getMethodName() << "\n";
        // Remove plant from inventory, update records, etc.
    }
    else
    {
        std::cout << "Payment failed!\n";
    }
}

void Cashier::setPaymentStrategy(PaymentStrategy *strategy)
{
    paymentStrategy = (strategy);
}

std::string Cashier::getPaymentMethod() const
{
    return paymentStrategy ? paymentStrategy->getMethodName() : "No method set";
}

void Cashier::update(NurseryPlant *plant)
{
    std::cout << getName() << " notified: " << plant->getName()
              << " reached " << plant->getStateName() << ".\n";

    if (plant->getStateName() == "Mature")
    {
        std::cout << getName() << " adding " << plant->getName()
                  << " to inventory for sale.\n";
        inventory->addPlant(plant->getName(), plant);
    }
}