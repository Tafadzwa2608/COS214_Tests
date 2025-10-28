/**
 * @file Command.h
 * @brief Abstract base class for all command types.
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <iostream>

/**
 * @class Command
 * @brief Interface for executing and undoing commands.
 */
class Command {
public:
    /**
     * @brief Executes the command.
     */
    virtual void execute() = 0;

    /**
     * @brief Undoes the command. Default implementation prints a message.
     */
    virtual void undo() { std::cout << "(Undo not implemented)\n"; }

    /**
     * @brief Virtual destructor.
     */
    virtual ~Command() = default;
};

#endif
