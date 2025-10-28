#include "OrderSlip.h"
#include <iostream>
using namespace std;

OrderSlip::OrderSlip(Order* order): SlipTemplate(order)
{
}

OrderSlip::~OrderSlip() {}

void OrderSlip::gatherData()
{
    cout << "Gathering order details..." << endl;
}

void OrderSlip::formatData()
{
    cout << "Order ID: " << order->getID() << endl;
    cout << "Total Amount: $" << order->getTotal() << endl;
}
