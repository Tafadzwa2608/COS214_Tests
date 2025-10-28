#ifndef ITERATOR_H
#define ITERATOR_H

#include "Order.h"
class Order; 
/**
 * @class Iterator
 * @brief Abstract base class defining the interface for iterating over Order objects.
 */
class Iterator
{
public:
    /** Virtual destructor for safe polymorphic deletion. */
    virtual ~Iterator();

    /**
     * @brief Checks if there are more elements to iterate over.
     * @return True if there are remaining elements, false otherwise.
     */
    virtual bool hasNext() const = 0;

    /**
     * @brief Returns the next Order object in the collection.
     * @return Pointer to the next Order.
     */
    virtual Order *next() = 0;
};

#endif


