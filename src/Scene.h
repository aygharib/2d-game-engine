#pragma once

#include "EntityManager.h"

#include <map>
#include <string>

class GameEngine;

class Scene {
public:
    EntityManager entityManager{};
    GameEngine*   gameEngine{};
    
    int  currentFrame{0};
    bool paused      {false};
    bool hasEnded    {false};

    Scene(GameEngine* gameEngine);
    
    virtual auto update() -> void = 0;
    virtual auto render() -> void = 0;
    virtual auto doAction(sf::Event event) -> void = 0;
};
