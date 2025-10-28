#ifndef BULKORDER_H
#define BULKORDER_H

#include "Order.h"
#include "OrderIterator.h"
#include <vector>
#include <iostream>
using namespace std;

/**
 * @class BulkOrder
 * @brief Composite class that represents a collection of multiple orders.
 *
 * Implements the Composite design pattern by allowing groups of
 * Order objects (including other BulkOrders) to be treated as a single order.
 */
class BulkOrder : public Order
{
private:
    /** @brief List of individual orders contained in this bulk order. */
    vector<Order *> orders;

public:
    /** @brief Constructs an empty BulkOrder (composite container of orders). */
    BulkOrder();

    /** @brief Default destructor for bulk orders*/
    virtual ~BulkOrder();

    /** @brief Adds an order to the bulk order. */
    void addOrder(Order *order);

    /** @brief Removes an order from the bulk order. */
    void removeOrder(Order *order);

    /** @brief Calculates and returns the total cost of all contained orders. */
    double getTotal() override;

    /** @brief Displays the details of all contained orders. */
    void displayDetails() override;

    /** @brief Calculates and displays tax information for all contained orders. */
    void calculateTax() override;

    /** @brief Creates and returns a deep copy of this BulkOrder and all its contents. */
    Order *clone() const override;

    /**
     * @brief Creates an iterator to traverse the contained orders.
     * @return Pointer to a new OrderIterator for the entire collection.

     */
    Iterator *createIterator();
};

#endif
