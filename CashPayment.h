/**
 * @file CashPayment.h
 * @brief Concrete strategy for processing cash payments.
 */

#ifndef CASHPAYMENT_H
#define CASHPAYMENT_H

#include "PaymentStrategy.h"
#include <iostream>

/**
 * @class CashPayment
 * @brief Implements cash payment processing strategy.
 *
 * Handles cash transactions including change calculation.
 * Validates that tendered amount covers the purchase total.
 */
class CashPayment : public PaymentStrategy
{
private:
    double tenderedAmount; /** The amount of cash tendered by customer */

public:
    /**
     * @brief Constructs a CashPayment strategy.
     * @param tendered The amount of cash provided by customer.
     */
    CashPayment(double tendered);

    /**
     * @brief Processes cash payment and calculates change.
     * @param amount The total amount due.
     * @return true if tendered amount covers total, false otherwise.
     */
    bool processPayment(double amount) override;

    /**
     * @brief Gets the payment method name.
     * @return "Cash" string.
     */
    std::string getMethodName() const override;

    /**
     * @brief Gets transaction details including tendered amount.
     * @return String with cash payment details.
     */
    std::string getTransactionDetails() const override;
};

#endif // CASHPAYMENT_H