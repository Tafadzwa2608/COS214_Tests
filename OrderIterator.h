#ifndef ORDERITERATOR_H
#define ORDERITERATOR_H

#include "Iterator.h"
#include <vector>
using namespace std;
/**
 * @class OrderIterator
 * @brief Concrete implementation of Iterator for iterating over a vector of Order pointers.
 *
 * This class implements the Iterator interface for a collection of Order objects,
 * allowing sequential traversal.
 */
class OrderIterator : public Iterator
{
private:
    vector<Order*>::iterator current;  /** Current position in the collection. */
    vector<Order*>::iterator endIter;  /** End position (one past the last element). */

public:
    /**
     * @brief Constructs an OrderIterator for a given range of orders.
     * @param start Iterator pointing to the start of the collection.
     * @param end Iterator pointing to one past the end of the collection.
     */
    OrderIterator(vector<Order*>::iterator start, vector<Order*>::iterator end);

    /**
     * @copydoc Iterator::hasNext()
     */
    bool hasNext() const override;

    /**
     * @copydoc Iterator::next()
     */
    Order* next() override;
};

#endif
