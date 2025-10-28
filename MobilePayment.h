/**
 * @file MobilePayment.h
 * @brief Concrete strategy for processing mobile payments.
 */

#ifndef MOBILEPAYMENT_H
#define MOBILEPAYMENT_H

#include "PaymentStrategy.h"
#include <iostream>
#include <string>

/**
 * @class MobilePayment
 * @brief Implements mobile payment processing strategy.
 * 
 * Handles mobile payment services like PayPal, Venmo, etc.
 * Simulates mobile payment processing.
 */
class MobilePayment : public PaymentStrategy {
private:
    std::string phoneNumber;   /**< Customer's phone number */
    std::string provider;      /**< Mobile payment provider */

public:
    /**
     * @brief Constructs a MobilePayment strategy.
     * @param phone The customer's phone number.
     * @param prov The payment provider (e.g., "PayPal", "Venmo").
     */
    MobilePayment(const std::string& phone, const std::string& prov);

    /**
     * @brief Processes mobile payment.
     * @param amount The amount to charge.
     * @return true if payment successful (simulated), false otherwise.
     */
    bool processPayment(double amount) override;

    /**
     * @brief Gets the payment method name.
     * @return "Mobile Payment" string.
     */
    std::string getMethodName() const override;

    /**
     * @brief Gets provider and phone details.
     * @return String with provider and phone information.
     */
    std::string getTransactionDetails() const override;
};

#endif // MOBILEPAYMENT_H