#pragma once

#include "EntityManager.h"

#include <map>
#include <string>

class GameEngine;

enum class Action {
    JUMP = 33,
    CROUCH = 44,
    RUN_LEFT = 55,
    RUN_RIGHT = 66
};

class Scene {
public:
    std::map<int, Action> actionMap{};
    EntityManager         entityManager{};
    GameEngine*           gameEngine{};
    
    int  currentFrame{0};
    bool paused      {false};
    bool hasEnded    {false};

    Scene(GameEngine* gameEngine);
    
    virtual auto update() -> void = 0;
    virtual auto render() -> void = 0;
    virtual auto doAction(Action action, bool isPressed) -> void = 0;
    virtual auto registerAction(sf::Keyboard::Key keycode, Action action)  -> void = 0;
};