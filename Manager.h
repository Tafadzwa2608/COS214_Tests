
/**
 * @file Manager.h
 * @brief Declaration of the Manager class, derived from Staff.
 */

#ifndef MANAGER_H
#define MANAGER_H

#include "Staff.h"
#include <iostream>

/**
 * @class Manager
 * @brief Represents a manager who handles customer disputes and oversees staff.
 */
class Manager : public Staff
{

public:
    /**
     * @brief Constructs a Manager with access to the inventory.
     * @param inventory Pointer to the Inventory object.
     * @param name Name of the manager.
     */
    Manager(Inventory *inventory, const std::string &name);

    /**
     * @brief Default destructor.
     */
    ~Manager() override = default;

    /**
     * @brief Handles a dispute raised by a customer.
     * @param customerName Name of the customer in dispute.
     * @param issue Description of the issue raised by the customer.
     */
    void handleDispute(const std::string &customerName, const std::string &issue);

    /**
     * @brief Reviews staff performance.
     */
    void reviewStaffPerformance();

    /**
     * @brief Gets list of staff members under management.
     */
    const std::vector<std::string> &getStaffMembers() const
    {
        return staffMembers;
    }

    /**
     * @brief Adds a staff member to the management roster.
     * @param staffName Name of staff member to be added.
     */
    void addStaffMember(const std::string &staffName)
    {
        staffMembers.push_back(staffName);
    }

    void update(NurseryPlant *plant) override;

private:
    std::vector<std::string> staffMembers; // List of staff under management
};

#endif // MANAGER_H
