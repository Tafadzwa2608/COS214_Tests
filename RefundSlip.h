#ifndef REFUNDSLIP_H
#define REFUNDSLIP_H

#include "SlipTemplate.h"
#include <string>
using namespace std;

/**
 * @class RefundSlip
 * @brief Concrete subclass of SlipTemplate for generating a refund slip.
 *
 * Uses the associated Order to determine the refund amount (full order total).
 * Implements the gatherData() and formatData() steps of the Template Method.
 */
class RefundSlip : public SlipTemplate {
private:
    string refundID; /**< Unique ID of the refund */

public:
    /**
     * @brief Constructs a RefundSlip for a given Order.
     * @param order Pointer to the Order associated with this refund.
     */
    RefundSlip(Order* order);

    /** @brief Destructor for RefundSlip. */
    ~RefundSlip() override;

protected:
    /** @brief Gathers refund-specific data. */
    void gatherData() override;

    /** @brief Formats and prints the refund slip data. */
    void formatData() override;
};

#endif
