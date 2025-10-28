#ifndef DISPUTEHANDLER_H
#define DISPUTEHANDLER_H

#include "Issue.h"

/**
 * @class DisputeHandler
 * @brief Abstract base class for handling issues in a chain of responsibility.
 */
class DisputeHandler
{
protected:
    /**
     * @brief Check if this handler can process the issue.
     */
    virtual bool canHandle(Issue *issue) = 0;

    /**
     * @brief Process the issue (implement in concrete handlers).
     */
    virtual void processIssue(Issue *issue) = 0;

public:
    /**
     * @brief Constructs a DisputeHandler with no next handler.
     */
    DisputeHandler();

    /**
     * @brief Virtual destructor that also deletes the next handler to avoid memory leaks.
     */
    virtual ~DisputeHandler();

    /**
     * @brief Sets the next handler in the chain.
     * @param next Pointer to the next DisputeHandler.
     */
    void setNext(DisputeHandler *next);

    /**
     * @brief Handles an issue or passes it to the next handler if unhandled.
     * @param issue Pointer to the Issue object to be processed.
     */
    virtual void handle(Issue *issue);

protected:
    /** Pointer to the next handler in the chain. */
    DisputeHandler *next;
};

#endif
