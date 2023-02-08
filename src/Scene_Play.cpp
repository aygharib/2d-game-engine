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

    spawnPlayer();
    spawnEnemy();
}

auto Scene_Play::registerAction(sf::Keyboard::Key keycode, Action action) -> void {
    actionMap[keycode] = action;
}

auto Scene_Play::doAction(sf::Event event) -> void {
    // Do not invoke action if the action is not registered for the scene
    if (!hasRegisteredAction(event.key.code)) {
        return;
    }

    auto action = actionMap.at(event.key.code);
    auto isPressed = (event.type == sf::Event::KeyPressed) ? true : false;

    auto a = player->hasComponent<CInput>();
    auto& inputComponent = player->getComponent<CInput>();

    if (isPressed) {
        switch (action) {
            case Action::JUMP: inputComponent.up = true; break;
            case Action::CROUCH: inputComponent.down = true; break;
            case Action::RUN_LEFT: inputComponent.left = true; break;
            case Action::RUN_RIGHT: inputComponent.right = true; break;
        }
    }
    else {
        switch (action) {
            case Action::JUMP: inputComponent.up = false; break;
            case Action::CROUCH: inputComponent.down = false; break;
            case Action::RUN_LEFT: inputComponent.left = false; break;
            case Action::RUN_RIGHT: inputComponent.right = false; break;
        }
    }
}

auto Scene_Play::spawnPlayer() -> void {
    player = entityManager.addEntity("player");
    player->addComponent<CInput>();
    player->addComponent<CTransform>(Vec2{100.F, 100.F});
    player->addComponent<CShape>(30.F, 30.F);
    player->addComponent<CBoundingBox>(Vec2{30.F, 30.F});
}

auto Scene_Play::spawnEnemy() -> void {
    auto enemy = entityManager.addEntity("enemy");
    enemy->addComponent<CTransform>(Vec2{300.F, 300.F});
    enemy->addComponent<CShape>(30.F, 30.F);
    enemy->addComponent<CBoundingBox>(Vec2{30.F, 30.F});
}

auto Scene_Play::update() -> void {
    entityManager.update();

    sMovement();
    sCollision();
}

auto Scene_Play::render() -> void {
    auto& playerTransformComponent = player->getComponent<CTransform>();
    view.setCenter(playerTransformComponent.position.x, playerTransformComponent.position.y);
    gameEngine->window.setView(view);

    auto a = entityManager.entities;
    for (auto e : entityManager.entities) {
        // Update position
        auto& transformComponent = e->getComponent<CTransform>();
        auto& shapeComponent = e->getComponent<CShape>();
        shapeComponent.shape.setPosition({transformComponent.position.x, transformComponent.position.y});

        // Draw
        gameEngine->window.draw(shapeComponent.shape);
    }
}

auto Scene_Play::sMovement() -> void {
    Vec2 playerVelocity{0.F, 0.F};

    auto& inputComponent = player->getComponent<CInput>();

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

    auto& transformComponent = player->getComponent<CTransform>();

    transformComponent.previousPosition = transformComponent.position;
    transformComponent.position += playerVelocity;
}

auto Scene_Play::sCollision() -> void {
    auto& inputComponent = player->getComponent<CInput>();
    auto& transformComponent = player->getComponent<CTransform>();

    for (auto& e : entityManager.getEntities("enemy")) {
        auto overlap = Physics::getOverlap(player, e);

        // If there's a collision, we want to push the player out of the enemy
        if (overlap.x > 0 && overlap.y > 0) {
            auto previousOverlap = Physics::getPreviousOverlap(player, e);

            if (previousOverlap.x > 0) {
                // Player coming from top or bottom of enemy

                if (inputComponent.down) { // player coming from top
                    transformComponent.position += Vec2{0.F, -overlap.y};
                }
                else if (inputComponent.up) { // player coming from bottom
                    transformComponent.position += Vec2{0.F, overlap.y};
                }
            }
            else if (previousOverlap.y > 0) {
                // Player coming from left or right of enemy

                if (inputComponent.right) { // player coming from left
                    transformComponent.position += Vec2{-overlap.x, 0.F};
                }
                else if (inputComponent.left) { // player coming from right
                    transformComponent.position += Vec2{overlap.x, 0.F};
                }
            }
        }
    }
}

auto Scene_Play::hasRegisteredAction(sf::Keyboard::Key keycode) -> bool {
    return actionMap.find(keycode) != actionMap.end();
}
