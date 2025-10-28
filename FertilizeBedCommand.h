/**
 * @file FertilizeBedCommand.h
 * @brief Command to fertilize a plant bed.
 */

#ifndef FERTILIZEBEDCOMMAND_H
#define FERTILIZEBEDCOMMAND_H

#include "Command.h"
#include "NurseryPlant.h"
#include "Customer.h"
#include "Order.h"

/**
 * @class FertilizeBedCommand
 * @brief Executes fertilization of a specific bed.
 */
class FertilizeBedCommand : public Command {
private:
    Order* order; ///Associated order (optional use)
    std::string bedName; //Name of the bed to fertilize
public:
    /**
     * @brief Constructs the command with the bed name.
     * @param b Name of the bed
     */
    FertilizeBedCommand(std::string b);

    /**
     * @brief Executes the fertilization process.
     */
    void execute() override;
};

#endif
