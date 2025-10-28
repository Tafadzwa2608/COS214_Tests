/**
 * @file Observer.h
 * @brief Header file for the Observer abstract base class in the Observer pattern.
 */

#ifndef OBSERVER_H
#define OBSERVER_H

#include "State.h"

class NurseryPlant;

/**
 * @brief Abstract base class for observers in the Observer pattern.
 *
 * Observers are notified when the state of a subject (NurseryPlant) changes.
 */
class Observer {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~Observer() = default;

    /**
     * @brief Updates the observer with information about a plant's state change.
     * @param plant Pointer to the NurseryPlant that changed state.
     */
    virtual void update(NurseryPlant* plant) = 0;
};

#endif
