#pragma once

#include "Scene.h"

#include <memory>
#include <SFML/Window/Keyboard.hpp>

#include "Entity.h"
#include "EntityManager.h"

class Scene_Play : public Scene {
public:
    std::shared_ptr<Entity> player{};

    Scene_Play(GameEngine* gameEngine);

    auto update() -> void override;
    auto render() -> void override;
    auto registerAction(Action action, sf::Keyboard::Key keycode) -> void override;
    auto doAction(sf::Keyboard::Key keycode, bool isPressed) -> void override;
    
    auto spawnPlayer() -> void;
    auto spawnEnemy() -> void;

    auto sMovement()  -> void;
    auto sCollision() -> void;
};