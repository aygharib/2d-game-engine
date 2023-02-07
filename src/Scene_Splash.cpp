#include "Scene_Splash.h"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Color.hpp>

#include "GameEngine.h"

Scene_Splash::Scene_Splash(GameEngine* gameEngine) : Scene(gameEngine) {
    registerAction(sf::Keyboard::Escape, Action::GO_TO_PLAY);
}

auto Scene_Splash::registerAction(sf::Keyboard::Key keycode, Action action) -> void {
    actionMap[keycode] = action;
}

auto Scene_Splash::doAction(Action action, bool isPressed) -> void {
    if (isPressed) {
        switch (action) {
            case Action::GO_TO_PLAY:
                gameEngine->setCurrentScene(1);
                std::cout << "escape clicked!\n";
                break;
        }
    }
}

auto Scene_Splash::update() -> void {
}

auto Scene_Splash::render() -> void {
    // Clear Screen
    gameEngine->window.clear(sf::Color::Black);

    // std::cout << "rendering splash\n";
    // std::cout << "...\n";
    
    // auto a = entityManager.entities;
    // for (auto e : entityManager.entities) {
    //     // Update position
    //     auto transformComponent = e->getCTransformComponent();
    //     auto shapeComponent = e->getCShapeComponent();
    //     shapeComponent.shape.setPosition({transformComponent.position.x, transformComponent.position.y});

    //     // Draw
    //     gameEngine->window.draw(shapeComponent.shape);
    // }
}