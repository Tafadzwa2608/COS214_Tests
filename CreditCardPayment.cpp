
#include "CreditCardPayment.h"

CreditCardPayment::CreditCardPayment(const std::string& card, const std::string& expiry) 
    : cardNumber(card), expiryDate(expiry) {}

bool CreditCardPayment::processPayment(double amount) {
    // Simulate card processing with basic validation
    if (cardNumber.length() != 16) {
        std::cout << "Invalid card number length!" << std::endl;
        return false;
    }
    
    std::cout << "Processing credit card payment of $" << amount << std::endl;
    std::cout << "Card: ****-****-****-" << cardNumber.substr(12) << std::endl;
    std::cout << "Expiry: " << expiryDate << std::endl;
    
    // Simulate processing delay
    std::cout << "Authorization approved." << std::endl;
    return true;
}

std::string CreditCardPayment::getMethodName() const { 
    return "Credit Card"; 
}

std::string CreditCardPayment::getTransactionDetails() const {
    return "Credit Card - Ending: " + cardNumber.substr(12);
}