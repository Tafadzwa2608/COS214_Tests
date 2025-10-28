/**
 * @file State.h
 * @brief Header file for the State abstract base class in the State pattern.
 */

#ifndef STATE_H
#define STATE_H

#include <string>

class NurseryPlant;

/**
 * @brief Abstract base class for plant states in the State pattern.
 *
 * This class defines the interface for different states a NurseryPlant can be in,
 * such as Seedling, Sprout, Mature, etc. Each state handles actions differently.
 */
class State {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~State() = default;

    /**
     * @brief Handles the action for the current state.
     * @param plant Pointer to the NurseryPlant object.
     */
    virtual void handleAction(NurseryPlant* plant) = 0;

    /**
     * @brief Gets the name of the state.
     * @return The name of the state as a string.
     */
    virtual std::string getStateName() const = 0;
};

#endif
