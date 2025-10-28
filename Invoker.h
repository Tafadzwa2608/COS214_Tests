/**
 * @file Invoker.h
 * @brief Manages and executes queued commands.
 */

#ifndef INVOKER_H
#define INVOKER_H

#include "Command.h"
#include <vector>
#include <queue>

/**
 * @class Invoker
 * @brief Queues and processes commands.
 */
class Invoker {
private:
    std::queue<Command*> commandQueue; ///Queue of commands to execute
public:
    /**
     * @brief Adds a command to the queue.
     * @param c Pointer to the command
     */
    void addCommand(Command* c);

    /**
     * @brief Processes all queued commands.
     */
    void processCommands();
};

#endif
