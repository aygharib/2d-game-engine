#pragma once

#include "EntityManager.h"

#include <map>
#include <string>

class GameEngine;

enum class Action {
    JUMP = 33,
    CROUCH = 44,
    RUN_LEFT = 55,
    RUN_RIGHT = 66,
    GO_TO_SPLASH = 77,
    GO_TO_PLAY = 88
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
    virtual auto registerAction(Action action, sf::Keyboard::Key keycode) -> void = 0;
    virtual auto doAction(sf::Keyboard::Key keycode, bool isPressed) -> void = 0;

    auto hasRegisteredAction(sf::Keyboard::Key keycode) -> bool;
};