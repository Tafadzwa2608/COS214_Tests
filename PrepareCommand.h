/**
 * @file PrepareCommand.h
 * @brief Command to prepare an order's plant.
 */

#ifndef PREPARECOMMAND_H
#define PREPARECOMMAND_H

#include "Command.h"
#include "Order.h"
#include <iostream>

/**
 * @class PrepareCommand
 * @brief Executes preparation of the plant in an order.
 */
class PrepareCommand : public Command {
public:
    /**
     * @brief Constructs the command with an order reference.
     * @param order Pointer to the order to prepare.
     */
    PrepareCommand(Order* order);

    /**
     * @brief Executes the preparation.
     */
    void execute() override;

private:
    Order* order; ///Pointer to the order being prepared.
};

#endif
