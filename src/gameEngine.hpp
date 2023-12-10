#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP
#include <SFML/Graphics.hpp>
#include "Objects/enemies.h"



/**
 * @brief The UniversalClock class represents a clock used for timing in the game engine.
 */
class UniversalClock {
public:
    /**
     * @brief Constructs a UniversalClock object.
     */
    UniversalClock() : clock() {}

    /**
     * @brief Checks if the specified delay time has passed.
     * @param delayTime The delay time in milliseconds.
     * @return True if the delay time has passed, false otherwise.
     */
    bool isDelayFinished(float delayTime) {
        return clock.getElapsedTime().asMilliseconds() >= delayTime;
    }

    /**
     * @brief Restarts the clock.
     */
    void restartClock() {
        clock.restart();
    }

private:
    sf::Clock clock; /**< The underlying SFML clock object. */
};
#endif
