#include "Scene_Splash.h"

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Color.hpp>

#include "GameEngine.h"

Scene_Splash::Scene_Splash(GameEngine* gameEngine) : Scene(gameEngine) {
    registerAction(Action::GO_TO_PLAY, sf::Keyboard::Escape);
}

auto Scene_Splash::registerAction(Action action, sf::Keyboard::Key keycode) -> void {
    actionMap[keycode] = action;
}

auto Scene_Splash::doAction(sf::Keyboard::Key keycode, bool isPressed) -> void {
    auto action = actionMap.at(keycode);

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