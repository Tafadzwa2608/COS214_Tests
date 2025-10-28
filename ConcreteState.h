/**
 * @file ConcreteState.h
 * @brief Header file for concrete state classes in the State pattern.
 */

#ifndef CONCRETESTATE_H
#define CONCRETESTATE_H

#include "State.h"
#include "NurseryPlant.h"

/**
 * @brief Represents the Seedling state of a plant.
 *
 * In this state, the plant is newly planted and may still be growing or need more time.
 */
class SeedlingState : public State {
public:
    /**
     * @brief Handles the action for the Seedling state.
     * @param plant Pointer to the NurseryPlant object.
     */
    void handleAction(NurseryPlant* plant) override;

    /**
     * @brief Gets the name of the state.
     * @return "Seedling"
     */
    std::string getStateName() const override;
};

/**
 * @brief Represents the Sprout state of a plant.
 *
 * In this state, the plant is growing leaves and needs nutrients. It may mature or be attacked by pests.
 */
class SproutState : public State {
public:
    /**
     * @brief Handles the action for the Sprout state.
     * @param plant Pointer to the NurseryPlant object.
     */
    void handleAction(NurseryPlant* plant) override;

    /**
     * @brief Gets the name of the state.
     * @return "Sprout"
     */
    std::string getStateName() const override;
};

/**
 * @brief Represents the Mature state of a plant.
 *
 * In this state, the plant is fully grown, flowering, and may need pruning.
 */
class MatureState : public State {
public:
    /**
     * @brief Handles the action for the Mature state.
     * @param plant Pointer to the NurseryPlant object.
     */
    void handleAction(NurseryPlant* plant) override;

    /**
     * @brief Gets the name of the state.
     * @return "Mature"
     */
    std::string getStateName() const override;
};

/**
 * @brief Represents the Wilting state of a plant.
 *
 * In this state, the plant is wilting and needs immediate care to recover.
 */
class WiltingPlantState : public State {
public:
    /**
     * @brief Handles the action for the Wilting state.
     * @param plant Pointer to the NurseryPlant object.
     */
    void handleAction(NurseryPlant* plant) override;

    /**
     * @brief Gets the name of the state.
     * @return "Wilting"
     */
    std::string getStateName() const override;
};

#endif // CONCRETESTATE_H
