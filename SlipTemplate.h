#ifndef SLIPTEMPLATE_H
#define SLIPTEMPLATE_H

#include <iostream>
#include <string>
#include "Order.h"
using namespace std;

/**
 * @class SlipTemplate
 * @brief Abstract base class defining the template method for printing slips.
 *
 * The printSlip() method defines the skeleton of the slip printing algorithm,
 * while derived classes implement specific steps like gatherData() and formatData().
 */
class SlipTemplate
{
protected:
    Order *order; /** Pointer to the associated Order object */

public:
    /**
     * @brief Constructs a SlipTemplate for a given Order.
     * @param order Pointer to the order to associate with this slip.
     */
    SlipTemplate(Order *order);

    /** @brief Virtual destructor. */
    virtual ~SlipTemplate();

    /**
     * @brief Template method that prints the complete slip.
     * Calls: printHeader(), gatherData(), formatData(), printFooter().
     */
    void printSlip();

    /**
     * @brief Sets or changes the associated order.
     * @param o Pointer to the new Order object.
     */
    virtual void setOrder(Order *o);

protected:
    /** @brief Prints the header section of the slip. */
    virtual void printHeader();

    /** @brief Gathers data needed for the slip (abstract step). */
    virtual void gatherData() = 0;

    /** @brief Formats and displays the slip data (abstract step). */
    virtual void formatData() = 0;

    /** @brief Prints the footer section of the slip. */
    virtual void printFooter();
};

#endif
