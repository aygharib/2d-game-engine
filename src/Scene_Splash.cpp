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

auto Scene_Splash::doAction(sf::Event event) -> void {
    // Do not invoke action if the action is not registered for the scene
    if (!hasRegisteredAction(event.key.code)) {
        return;
    }

    auto action = actionMap.at(event.key.code);
    auto isPressed = (event.type == sf::Event::KeyPressed) ? true : false;

    if (isPressed) {
        switch (action) {
            case Action::GO_TO_PLAY: gameEngine->setCurrentScene(1); break;
        }
    }
}

auto Scene_Splash::update() -> void {
}

auto Scene_Splash::render() -> void {
}

auto Scene_Splash::hasRegisteredAction(sf::Keyboard::Key keycode) -> bool {
    return actionMap.find(keycode) != actionMap.end();
}
