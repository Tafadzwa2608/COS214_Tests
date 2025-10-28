/**
 * @file Subject.h
 * @brief Header file for the Subject abstract base class in the Observer pattern.
 */

#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

/**
 * @brief Abstract base class for subjects in the Observer pattern.
 *
 * Subjects maintain a list of observers and notify them of state changes.
 */
class Subject {
public:
    /**
     * @brief Virtual destructor.
     */
    virtual ~Subject() = default;

    /**
     * @brief Attaches an observer to this subject.
     * @param observer Pointer to the observer to attach.
     */
    virtual void attach(Observer* observer) = 0;

    /**
     * @brief Detaches an observer from this subject.
     * @param observer Pointer to the observer to detach.
     */
    virtual void detach(Observer* observer) = 0;

    /**
     * @brief Notifies all attached observers of a change.
     */
    virtual void notify() = 0;
};

#endif
