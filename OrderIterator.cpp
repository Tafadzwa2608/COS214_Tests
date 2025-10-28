#include "OrderIterator.h"
#include <stdexcept>

OrderIterator::OrderIterator(vector<Order*>::iterator start, vector<Order*>::iterator end)
    : current(start), endIter(end)
{
}

bool OrderIterator::hasNext() const
{
    return current != endIter;
}

Order* OrderIterator::next()
{
    if (!hasNext())
        throw out_of_range("No more orders to iterate over.");

    return *current++;
}
