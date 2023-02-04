#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "EntityManager.h"

class Game {
public:
    Game();
    auto run() -> void;
private:
    sf::RenderWindow window;
    EntityManager entityManager;
    std::shared_ptr<Entity> player;

    auto init()       -> void;
    
    auto sUserInput() -> void;
    auto sMovement()  -> void;
    auto sCollision() -> void;
    auto sRender()    -> void;

    auto spawnPlayer() -> void;
};