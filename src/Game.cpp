#include <iostream>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "Game.h"
#include "CInput.h"
#include "CShape.h"
#include "CTransform.h"
#include "Vec2.h"

Game::Game() {
    init();
}

auto Game::init() -> void {
    window.create(sf::VideoMode(1280, 720), "2D Game Engine");
    window.setFramerateLimit(60);

    spawnPlayer();
}

auto Game::run() -> void {
    while (window.isOpen()) {
        entityManager.update();

        sUserInput();
        sMovement();
        sCollision();
        sRender();
    }
}

auto Game::sUserInput() -> void {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Up
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                player->cInput->up = true;
            }
        }
        else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Up) {
                player->cInput->up = false;
            }
        }

        // Down
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Down) {
                player->cInput->down = true;
            }
        }
        else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Down) {
                player->cInput->down = false;
            }
        }

        // Left
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Left) {
                player->cInput->left = true;
            }
        }
        else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Left) {
                player->cInput->left = false;
            }
        }

        // Right
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right) {
                player->cInput->right = true;
            }
        }
        else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Right) {
                player->cInput->right = false;
            }
        }

        // Mouse input
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.key.code == sf::Mouse::Left) {
                // Spawn Enemy
                auto entity = entityManager.addEntity("enemy");
                entity->cTransform = std::make_shared<CTransform>(Vec2{(float)event.mouseButton.x, (float)event.mouseButton.y}, Vec2{0, 0}, 0.F);
                entity->cShape = std::make_shared<CShape>(50.F, 8);
                entity->cInput = std::make_shared<CInput>();
            }
            else if (event.key.code == sf::Mouse::Right) {
                // Delete enemy
                entityManager.removeEntity("enemy");
            }
        }
    }
}

auto Game::sMovement() -> void {
    player->cTransform->velocity = Vec2{0, 0};

    if (player->cInput->up) {
        player->cTransform->velocity.y = -5.0F;
    }
    if (player->cInput->down) {
        player->cTransform->velocity.y =  5.0F;
    }
    if (player->cInput->left) {
        player->cTransform->velocity.x = -5.0F;
    }
    if (player->cInput->right) {
        player->cTransform->velocity.x =  5.0F;
    }

    player->cTransform->position += player->cTransform->velocity;
}

auto Game::sCollision() -> void {

}

auto Game::sRender() -> void {
    window.clear(sf::Color::Black);

    for (const auto& e : entityManager.getEntities()) {
        e->cShape->shape.setPosition(e->cTransform->position.x, e->cTransform->position.y);
        window.draw(e->cShape->shape);
    }

    window.display();
}

auto Game::spawnPlayer() -> void {
    auto entity = entityManager.addEntity("player");

    entity->cTransform = std::make_shared<CTransform>(Vec2{300, 300}, Vec2{0, 0}, 0.F);
    entity->cShape = std::make_shared<CShape>(50.F, 8);
    entity->cInput = std::make_shared<CInput>();

    player = entity;
}