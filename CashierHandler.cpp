#include "CashierHandler.h"
#include "DisputeHandler.h"
#include "Issue.h"

#include <iostream>

void CashierHandler::setPaymentStrategy(PaymentStrategy *strategy)
{
    delete payStrategy;
    payStrategy = strategy;
}
void CashierHandler::setSlipGenerator(SlipTemplate *slip)
{
    delete slipGenerator;
    slipGenerator = slip;
}
void CashierHandler::processIssue(Issue *issue)
{
    std::cout << "CashierHandler processing: "
              << issue->getDescription() << std::endl;

    std::string issueType = issue->getID();
    Order *order = issue->getOrder();

    if (issueType == "Payment")
    {
        if (order && payStrategy)
        {
            double amount = order->getTotal();
            std::cout << "Processing payment of $" << amount << "..." << std::endl;

            if (payStrategy->processPayment(amount))
            {
                std::cout << "Payment successful via "
                          << payStrategy->getMethodName() << std::endl;
            }
            else
            {
                std::cout << "Payment failed!" << std::endl;
            }
        }
        else
        {
            std::cout << " Missing order or payment method!" << std::endl;
        }
    }
    else if (issueType == "Refund")
    {
        if (order)
        {
            std::cout << "Processing refund for Order #" << order->getID() << std::endl;
            std::cout << "Refund amount: $" << order->getTotal() << std::endl;

            if (slipGenerator)
            {
                slipGenerator->setOrder(order);
                slipGenerator->printSlip();
            }
        }
        else
        {
            std::cout << " No order associated with refund!" << std::endl;
        }
    }
    else
    {
        std::cout << "Handling general cashier issue..." << std::endl;
    }

    std::cout << "Cashier issue resolved.\n"
              << std::endl;
}

bool CashierHandler::canHandle(Issue *issue) 
{
    std::string id = issue->getID();
    return (id == "Payment" || id == "Refund" || id == "Cashier");
}

CashierHandler ::CashierHandler() : payStrategy(NULL), slipGenerator(NULL)
{
}

CashierHandler ::~CashierHandler()
{
    delete payStrategy;
    delete slipGenerator;
}