#ifndef CASHIERHANDLER_H
#define CASHIERHANDLER_H

#include "Issue.h"
#include "SlipTemplate.h"
#include "PaymentStrategy.h"
#include "DisputeHandler.h"
#include <string>

/**
 * @class CashierHandler
 * @brief Concrete handler that processes issues related to the cashier.
 *
 * If the issue ID matches "Cashier", this handler solves it.
 * Otherwise, it passes the issue to the next handler in the chain.
 */
class CashierHandler : public DisputeHandler
{
private:
    PaymentStrategy *payStrategy;
    SlipTemplate *slipGenerator;

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
     * @brief Constructs a CashierHandler with no next handler.
     */
    CashierHandler();

    /**
     * @brief Destroys the CashierHandler instance.
     */
    virtual ~CashierHandler();

    void setPaymentStrategy(PaymentStrategy *strategy);
    void setSlipGenerator(SlipTemplate *slip);
};

#endif
