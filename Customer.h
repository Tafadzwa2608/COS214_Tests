/**
 * @file Customer.h
 * @brief Represents a customer placing an order.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

/**
 * @class Customer
 * @brief Stores customer information.
 */
class Customer {
private:
    std::string name; // Name of the customer
public:
    /**
     * @brief Constructs a Customer with a given name.
     * @param n Name of the customer
     */
    Customer(std::string n);

    /**
     * @brief Gets the customer's name.
     * @return Name of the customer
     */
    std::string getName();
};

#endif
