/**
 * @file CreditCardPayment.h
 * @brief Concrete strategy for processing credit card payments.
 */

#ifndef CREDITCARDPAYMENT_H
#define CREDITCARDPAYMENT_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

/**
 * @class CreditCardPayment
 * @brief Implements credit card payment processing strategy.
 *
 * Handles credit card transactions with card number validation
 * and expiration date checking (simulated).
 */
class CreditCardPayment : public PaymentStrategy
{
private:
    std::string cardNumber; /**  Credit card number */
    std::string expiryDate; /** Card expiration date */

public:
    /**
     * @brief Constructs a CreditCardPayment strategy.
     * @param card The credit card number.
     * @param expiry The card expiration date (MM/YY format).
     */
    CreditCardPayment(const std::string &card, const std::string &expiry);

    /**
     * @brief Processes credit card payment.
     * @param amount The amount to charge.
     * @return true if payment successful (simulated), false otherwise.
     */
    bool processPayment(double amount) override;

    /**
     * @brief Gets the payment method name.
     * @return "Credit Card" string.
     */
    std::string getMethodName() const override;

    /**
     * @brief Gets masked card number for receipt.
     * @return String with last 4 digits of card.
     */
    std::string getTransactionDetails() const override;
};

#endif // CREDITCARDPAYMENT_H