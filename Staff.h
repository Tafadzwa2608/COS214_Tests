/**
 * @file Staff.h
 * @brief Header file for the Staff class, implementing the Observer pattern.
 */

#ifndef STAFF_H
#define STAFF_H

#include "Observer.h"
#include <string>
#include "Inventory.h"
#include "CareStrategy.h"
#include "Command.h"
#include "HighMaintenancePlantCare.h"

class NurseryPlant;

/**
 * @brief Represents a staff member who observes plant state changes and manages inventory.
 *
 * The Staff class implements the Observer interface to be notified when a plant's state changes.
 * When a plant reaches the Mature state, the staff adds it to the inventory.
 */
/**
 * @class Staff
 * @brief Represents a staff member who can care for plants and execute commands.
 */
class Staff : public Observer
{
private:
    std::string name; /// Name of the staff member
protected:
    CareStrategy *strategy; /// Strategy used to care for plants
    Inventory *inventory;

public:
    /**
     * @brief Constructs a Staff object with a reference to the inventory.
     * @param inventory Pointer to the Inventory object.
     * @param n Name of the staff member
     * @param s Pointer to a CareStrategy (default is nullptr)
     */
    Staff(Inventory *inventory, std::string n, CareStrategy *s = nullptr);

    /**
     * @brief Default destructor.
     */

    virtual ~Staff();

    /**
     * @brief Updates the staff when a plant's state changes.
     * @param plant Pointer to the NurseryPlant that changed state.
     */
    virtual void update(NurseryPlant *plant)
    {
        std::cout << "Staff notified" << std::endl;
    };

    /**
     * @brief Gets the name of the staff member.
     * @return A string representing the staff member's name.
     */
    std::string getName() const;

    /**
     * @brief Sets the care strategy for the staff member.
     * @param s Pointer to a CareStrategy
     */
    virtual void setStrategy(CareStrategy *s);

    /**
     * @brief Performs care for a given nursery plant using the assigned strategy.
     * @param plant Reference to the NurseryPlant to be cared for
     */
    virtual void careForPlant(NurseryPlant &plant);
    /**
     * @brief Executes a given command.
     * @param cmd Pointer to the Command to be executed
     */
    virtual void perform(Command *cmd);
};

#endif