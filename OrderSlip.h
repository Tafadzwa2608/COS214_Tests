#ifndef ORDERSLIP_H
#define ORDERSLIP_H

#include "SlipTemplate.h"
#include <string>
using namespace std;

/**
 * @class OrderSlip
 * @brief Concrete subclass of SlipTemplate for generating an order slip.
 *
 * Implements the gatherData() and formatData() steps of the Template Method
 * to collect and display order-specific information.
 */
class OrderSlip : public SlipTemplate
{
public:
    /**
     * @brief Constructs an OrderSlip associated with a given Order.
     * @param order Pointer to the Order to generate the slip for.
     */
    OrderSlip(Order* order);

    /** @brief Destructor for OrderSlip. */
    ~OrderSlip() override;

protected:
    /** @brief Gathers order-specific data. */
    void gatherData() override;

    /** @brief Formats and prints the order slip data. */
    void formatData() override;
};

#endif
