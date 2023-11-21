#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP
#include <SFML/Graphics.hpp>
#include "Objects/enemies.h"



class UniversalClock {
public:
    UniversalClock() : clock() {}

    // Function to check if the delay time has passed
    bool isDelayFinished(float delayTime) {
        return clock.getElapsedTime().asMilliseconds() >= delayTime;
    }

    // Function to restart the clock
    void restartClock() {
        clock.restart();
    }

private:
    sf::Clock clock;
};

#endif

void delayedFunction(UniversalClock &clock, float delayTime,Enemy &enemy1, sf::RenderWindow &window) {
    if (clock.isDelayFinished(delayTime)) {
        enemy1.moveEnemy(0.1,window);
        clock.restartClock();
    }
}