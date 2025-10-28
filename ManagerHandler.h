#ifndef MANAGERHANDLER_H
#define MANAGERHANDLER_H

#include "Issue.h"
#include "DisputeHandler.h"
#include <string>

/**
 * @class ManagerHandler
 * @brief Concrete handler that processes issues meant for the manager.
 *
 * If the issue ID matches "Manager", this handler solves it.
 * Otherwise, it passes the issue along the chain.
 */
class ManagerHandler : public DisputeHandler
{
protected:
    /**
     * DisputeHandler::processIssue(Issue* issue)
     */
    void processIssue(Issue *issue) override;

    /**
     * DisputeHandler::canHandle(Issue* issue)
     */
    bool canHandle(Issue *issue) override;

public:
    /**
     * @brief Constructs a ManagerHandler with no next handler.
     */
    ManagerHandler();

    /**
     * @brief Destroys the ManagerHandler instance.
     */
    virtual ~ManagerHandler();
};

#endif
