#include "PackageOrderCommand.h"

PackageOrderCommand::PackageOrderCommand(Order *o) : order(o) {}

void PackageOrderCommand::execute()
{
    std::cout << "Packaging order #" << order->getID() << "\n";
    order->setOrderStatus("packaged");
}
