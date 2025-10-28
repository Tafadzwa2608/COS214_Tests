/**
 * @file MobilePayment.cpp
 * @brief Implementation of MobilePayment class.
 */

#include "MobilePayment.h"

MobilePayment::MobilePayment(const std::string &phone, const std::string &prov)
    : phoneNumber(phone), provider(prov) {}

bool MobilePayment::processPayment(double amount)
{
    std::cout << "Processing " << provider << " payment from " << phoneNumber << std::endl;
    std::cout << "Amount: $" << amount << std::endl;
    std::cout << "Sending authorization request to " << provider << "..." << std::endl;
    std::cout << "Payment confirmed via mobile." << std::endl;
    return true;
}

std::string MobilePayment::getMethodName() const
{
    return "Mobile Payment";
}

std::string MobilePayment::getTransactionDetails() const
{
    return provider + " - " + phoneNumber;
}