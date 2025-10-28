/**
 * @file DeliverOrderCommand.h
 * @brief Command to deliver an order.
 */

#ifndef DELIVERORDERCOMMAND_H
#define DELIVERORDERCOMMAND_H

#include "Command.h"
#include "NurseryPlant.h"
#include "Customer.h"
#include "Order.h"

/**
 * @class DeliverOrderCommand
 * @brief Executes delivery of an order.
 */
class DeliverOrderCommand : public Command {
private:
    Order* order; ///Pointer to the order to be delivered
public:
    /**
     * @brief Constructs the command with the given order.
     * @param o Pointer to the order
     */
    DeliverOrderCommand(Order* o);

    /**
     * @brief Executes the delivery process.
     */
    void execute() override; 
};

#endif
