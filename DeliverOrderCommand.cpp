#include "DeliverOrderCommand.h"

DeliverOrderCommand::DeliverOrderCommand(Order* o) : order(o) {}

void DeliverOrderCommand::execute() {
        std::cout << "Delivering order #" << order->getID()
                  << " to " << order->getCustomer()->getName() << "\n";
        order->setOrderStatus("delivered");
    }

