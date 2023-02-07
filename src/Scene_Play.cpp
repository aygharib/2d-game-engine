#include "Scene_Play.h"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Color.hpp>
#include <tuple>

#include "CInput.h"
#include "CTransform.h"
#include "CShape.h"
#include "CBoundingBox.h"
#include "Physics.h"
#include "Vec2.h"

#include "GameEngine.h"

Scene_Play::Scene_Play(GameEngine* gameEngine) : Scene(gameEngine) {
    registerAction(sf::Keyboard::Up, Action::JUMP);
    registerAction(sf::Keyboard::Down, Action::CROUCH);
    registerAction(sf::Keyboard::Left, Action::RUN_LEFT);
    registerAction(sf::Keyboard::Right, Action::RUN_RIGHT);
    registerAction(sf::Keyboard::Escape, Action::GO_TO_SPLASH);

    spawnPlayer();
    spawnEnemy();
}

auto Scene_Play::registerAction(sf::Keyboard::Key keycode, Action action) -> void {
    actionMap[keycode] = action;
}

auto Scene_Play::doAction(Action action, bool isPressed) -> void {
    if (isPressed) {
        switch (action) {
            case Action::JUMP: player->getCInputComponent().up = true; break;
            case Action::CROUCH: player->getCInputComponent().down = true; break;
            case Action::RUN_LEFT: player->getCInputComponent().left = true; break;
            case Action::RUN_RIGHT: player->getCInputComponent().right = true; break;
            case Action::GO_TO_SPLASH: gameEngine->setCurrentScene(0); break;
        }
    }
    else {
        switch (action) {
            case Action::JUMP: player->getCInputComponent().up = false; break;
            case Action::CROUCH: player->getCInputComponent().down = false; break;
            case Action::RUN_LEFT: player->getCInputComponent().left = false; break;
            case Action::RUN_RIGHT: player->getCInputComponent().right = false; break;
        }
    }
}

auto Scene_Play::spawnPlayer() -> void {
    player = entityManager.addEntity("player");
    player->addCInputComponent(CInput{});
    player->addCTransformComponent(CTransform{Vec2{100.F, 100.F}});
    player->addCShapeComponent(CShape{30.F, 30.F});
    player->addCBoundingBoxComponent(CBoundingBox{Vec2{30.F, 30.F}});
}

auto Scene_Play::spawnEnemy() -> void {
    auto enemy = entityManager.addEntity("enemy");
    enemy->addCTransformComponent(CTransform{Vec2{300.F, 300.F}});
    enemy->addCShapeComponent(CShape{30.F, 30.F});
    enemy->addCBoundingBoxComponent(CBoundingBox{Vec2{30.F, 30.F}});
}

auto Scene_Play::update() -> void {
    entityManager.update();

    sMovement();
    sCollision();
}

auto Scene_Play::render() -> void {
    // Clear Screen
    gameEngine->window.clear(sf::Color::Black);
    
    auto a = entityManager.entities;
    for (auto e : entityManager.entities) {
        // Update position
        auto transformComponent = e->getCTransformComponent();
        auto shapeComponent = e->getCShapeComponent();
        shapeComponent.shape.setPosition({transformComponent.position.x, transformComponent.position.y});

        // Draw
        gameEngine->window.draw(shapeComponent.shape);
    }
}

auto Scene_Play::sMovement() -> void {
    Vec2 playerVelocity{0.F, 0.F};

    auto inputComponent = player->getCInputComponent();

    if (inputComponent.up) {
        playerVelocity.y = -3;
    }
    if (inputComponent.down) {
        playerVelocity.y = 3;
    }
    if (inputComponent.left) {
        playerVelocity.x = -3;
    }
    if (inputComponent.right) {
        playerVelocity.x = 3;
    }
    player->getCTransformComponent().previousPosition = player->getCTransformComponent().position;
    player->getCTransformComponent().position += playerVelocity;
}

auto Scene_Play::sCollision() -> void {
    for (auto& e : entityManager.getEntities("enemy")) {
        auto overlap = Physics::getOverlap(player, e);

        // If there's a collision, we want to push the player out of the enemy
        if (overlap.x > 0 && overlap.y > 0) {
            std::cout << "COLLISION\n";
            auto previousOverlap = Physics::getPreviousOverlap(player, e);
            std::cout << "CURRENT  OVERLAP: " << overlap.x << ", " << overlap.y << "\n";
            std::cout << "PREVIOUS OVERLAP: " << previousOverlap.x << ", " << previousOverlap.y << "\n";

            if (previousOverlap.x > 0) {
                // Player coming from top or bottom of enemy

                if (player->getCInputComponent().down) { // player coming from top
                    player->getCTransformComponent().position += Vec2{0.F, -overlap.y};
                }
                else if  (player->getCInputComponent().up) { // player coming from bottom
                    player->getCTransformComponent().position += Vec2{0.F, overlap.y};
                }
            }
            else if (previousOverlap.y > 0) {
                // Player coming from left or right of enemy

                if (player->getCInputComponent().right) { // player coming from left
                    player->getCTransformComponent().position += Vec2{-overlap.x, 0.F};
                }
                else if  (player->getCInputComponent().left) { // player coming from right
                    player->getCTransformComponent().position += Vec2{overlap.x, 0.F};
                }
            }
        }
    }
}