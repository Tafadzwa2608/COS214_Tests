/**
 * @file Cashier.h
 * @brief Cashier class that uses PaymentStrategy as context.
 */

#ifndef CASHIER_H
#define CASHIER_H

#include "Staff.h"
#include "LowMaintenancePlantCare.h"
#include "Inventory.h"
#include "PaymentStrategy.h"
#include <iostream>

/**
 * @class Cashier
 * @brief Handles customer transactions and manages sales using PaymentStrategy.
 */
class Cashier : public Staff
{
private:
    PaymentStrategy *paymentStrategy;

public:
    /**
     * @brief Constructs a Cashier with access to the inventory.
     * @param inventory Pointer to the Inventory object.
     * @param name Name of the cashier.
     */
    Cashier(Inventory *inventory, const std::string &name);

    /**
     * @brief Default destructor.
     */
    virtual ~Cashier() = default;

    /**
     * @brief Processes a sale for a given plant with payment.
     * @param plantName The name of the plant being sold.
     * @param amount The total amount to be paid.
     */
    void processSale(const std::string &plantName, double amount);

    /**
     * @brief Sets the payment strategy for this cashier.
     * @param strategy Unique pointer to the PaymentStrategy.
     */
    void setPaymentStrategy(PaymentStrategy *strategy);

    /**
     * @brief Gets the current payment method name.
     * @return Name of the current payment method.
     */
    std::string getPaymentMethod() const;

    void update(NurseryPlant *plant) override;
};

#endif // CASHIER_H