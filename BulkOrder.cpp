#include "BulkOrder.h"
#include <algorithm>
using namespace std;

BulkOrder::BulkOrder()
    : Order() {}

BulkOrder::~BulkOrder()
{
}

void BulkOrder::addOrder(Order *order)
{
    orders.push_back(order);
}

void BulkOrder::removeOrder(Order *order)
{
    orders.erase(remove(orders.begin(), orders.end(), order), orders.end());
}

double BulkOrder::getTotal()
{
    double total = 0;
    for (auto o : orders)
        total += o->getTotal();
    return total;
}

void BulkOrder::displayDetails()
{
    cout << "Bulk Order ID: " << orderID << endl;
    for (auto o : orders)
        o->displayDetails();
    cout << "Total Bulk Order Price: " << getTotal() << endl;
}

void BulkOrder::calculateTax()
{
    for (auto o : orders)
        o->calculateTax();
}

Order *BulkOrder::clone() const
{
    BulkOrder *copy = new BulkOrder();
    for (auto o : orders)
        copy->addOrder(o->clone());
    return copy;
}

Iterator *BulkOrder::createIterator()
{
    return new OrderIterator(orders.begin(), orders.end());
}
