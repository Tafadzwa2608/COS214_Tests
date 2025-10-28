#include "SlipTemplate.h"
#include <iostream>
using namespace std;

SlipTemplate::SlipTemplate(Order *order)
{
    if (order)
    {
        this->order = order;
    }
}

SlipTemplate::~SlipTemplate() {}

void SlipTemplate::printSlip()
{
    printHeader();
    gatherData();
    formatData();
    printFooter();
}

void SlipTemplate::setOrder(Order *o)
{
    if (o)
    {
        this->order = o;
    }
}

void SlipTemplate::printHeader()
{
    cout << "-----------------------------" << endl;
    cout << "         Slip Header         " << endl;
    cout << "-----------------------------" << endl;
}

void SlipTemplate::printFooter()
{
    cout << "-----------------------------" << endl;
    cout << "        End of Slip          " << endl;
    cout << "-----------------------------" << endl;
}
