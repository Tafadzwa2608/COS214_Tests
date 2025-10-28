#include "Invoker.h"

/**
 * @brief Adds a command to the queue.
 * @param c Pointer to the command
 */
void Invoker::addCommand(Command *c)
{
    commandQueue.push(c);
}

void Invoker::processCommands()
{
    while (!commandQueue.empty())
    {
        Command *cmd = commandQueue.front();
        commandQueue.pop();
        if (cmd)
        {
            cmd->execute();
        }
    }
}