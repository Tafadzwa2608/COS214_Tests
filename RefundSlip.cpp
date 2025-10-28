#include "RefundSlip.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>
using namespace std;

RefundSlip::RefundSlip(Order* order)
    : SlipTemplate(order)
{

    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm tm = *localtime(&now);
    ostringstream ss;
    ss << "RFD-" << order->getID() << "-" << put_time(&tm, "%Y%m%d%H%M%S");
    refundID = ss.str();
}

RefundSlip::~RefundSlip() {}

void RefundSlip::gatherData()
{
    cout << "Collecting refund information..." << endl;
}

void RefundSlip::formatData()
{
    cout << "Refund ID: " << refundID << endl;
    cout << "Refund Amount: $" << order->getTotal() << endl;
}
