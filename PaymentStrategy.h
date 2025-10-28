/**
 * @file PaymentStrategy.h
 * @brief Interface for all payment strategies in the nursery system.
 * 
 * Implements the Strategy pattern to allow flexible payment processing.
 * Different payment methods (cash, credit card, mobile) implement this interface.
 */

#ifndef PAYMENTSTRATEGY_H
#define PAYMENTSTRATEGY_H

#include <string>

/**
 * @class PaymentStrategy
 * @brief Abstract base class defining the interface for payment processing strategies.
 * 
 * This interface allows the system to process payments through different methods
 * (cash, credit card, mobile payments) interchangeably. The Cashier class uses
 * this strategy to process payments without knowing the specific payment method.
 */
class PaymentStrategy {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~PaymentStrategy() = default;

    /**
     * @brief Processes a payment for the given amount.
     * @param amount The amount to be processed.
     * @return true if payment was successful, false otherwise.
     */
    virtual bool processPayment(double amount) = 0;

    /**
     * @brief Gets the name of the payment method.
     * @return String representing the payment method name.
     */
    virtual std::string getMethodName() const = 0;

    /**
     * @brief Gets detailed transaction information.
     * @return String with transaction-specific details.
     */
    virtual std::string getTransactionDetails() const = 0;
};

#endif // PAYMENTSTRATEGY_H