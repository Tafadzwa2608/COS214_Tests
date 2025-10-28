
#include "CashPayment.h"

CashPayment::CashPayment(double tendered) : tenderedAmount(tendered) {}

bool CashPayment::processPayment(double amount)
{
    bool success = (tenderedAmount >= amount);
    if (success)
    {
        double change = tenderedAmount - amount;
        std::cout << "Cash payment processed. Change: $" << change << std::endl;
    }
    else
    {
        std::cout << "Insufficient cash. Tendered: $" << tenderedAmount
                  << ", Required: $" << amount << std::endl;
    }
    return success;
}

std::string CashPayment::getMethodName() const
{
    return "Cash";
}

std::string CashPayment::getTransactionDetails() const
{
    return "Cash - Tendered: $" + std::to_string(tenderedAmount);
}