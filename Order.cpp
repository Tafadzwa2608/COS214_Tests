#include "Order.h"
#include <iomanip>

Order::Order(double price, Customer *c)
{
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm tm = *localtime(&now);

    ostringstream ss;
    ss << "ORD-" << put_time(&tm, "%Y%m%d-%H%M%S")
       << "-" << (random_device{}() % 9000 + 1000);

    this->orderID = ss.str();
    this->price = price;
    customer = c;
}

Order::~Order()
{
}

string Order::getID()
{
    return orderID;
}

void Order::setOrderStatus(string status)
{
    this->orderStatus = status;
}

Customer *Order::getCustomer()
{
    return customer;
}
