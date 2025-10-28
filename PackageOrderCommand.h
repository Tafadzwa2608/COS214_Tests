/**
 * @file PackageOrderCommand.h
 * @brief Command to package an order.
 */

#ifndef PACKAGEORDERCOMMAND_H
#define PACKAGEORDERCOMMAND_H

#include "Command.h"
#include "Order.h"

/**
 * @class PackageOrderCommand
 * @brief Executes packaging of an order.
 */
class PackageOrderCommand : public Command {
private:
    Order* order; ///Pointer to the order
public:
    /**
     * @brief Constructs the command with an order.
     * @param o Pointer to the order
     */
    PackageOrderCommand(Order* o);

    /**
     * @brief Executes the packaging process.
     */
    void execute() override;
};

#endif
