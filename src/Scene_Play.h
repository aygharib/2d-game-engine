#pragma once

#include "Scene.h"

#include <memory>
#include <SFML/Window/Keyboard.hpp>

#include "Entity.h"
#include "EntityManager.h"

class Scene_Play : public Scene {
private:
    enum class Action {
        JUMP,
        CROUCH,
        RUN_LEFT,
        RUN_RIGHT,
        GO_TO_SPLASH,
        GO_TO_PLAY
    };

    std::map<int, Action> actionMap{};
    std::shared_ptr<Entity> player{};
public:
    Scene_Play(GameEngine* gameEngine);

    auto update() -> void override;
    auto render() -> void override;
    auto registerAction(sf::Keyboard::Key keycode, Action action) -> void;
    auto doAction(sf::Event event) -> void override;
    
    auto spawnPlayer() -> void;
    auto spawnEnemy() -> void;

    auto sMovement()  -> void;
    auto sCollision() -> void;
    
    auto hasRegisteredAction(sf::Keyboard::Key keycode) -> bool;
};