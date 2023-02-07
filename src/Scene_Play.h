#pragma once

#include <memory>
#include <SFML/Window/Keyboard.hpp>

#include "Entity.h"
#include "EntityManager.h"

class GameEngine;

enum class Action {
    JUMP = 33,
    CROUCH = 44,
    RUN_LEFT = 55,
    RUN_RIGHT = 66
};

class Scene_Play {
public:
    std::map<int, Action>  actionMap{};
    EntityManager           entityManager{};
    std::shared_ptr<Entity> player{};
    GameEngine* gameEngine{};

    Scene_Play(GameEngine* gameEngine);

    auto registerAction(sf::Keyboard::Key keycode, Action action) -> void;
    auto doAction(Action action, bool isPressed) -> void;
    
    auto spawnPlayer() -> void;
    auto spawnEnemy() -> void;

    auto update() -> void;
    auto render() -> void;

    auto sMovement()  -> void;
    auto sCollision() -> void;
};