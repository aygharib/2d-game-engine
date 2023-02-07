#pragma once

#include "Scene.h"

#include <memory>
#include <SFML/Window/Keyboard.hpp>

class Scene_Splash : public Scene {
public:
    Scene_Splash(GameEngine* gameEngine);

    auto update() -> void override;
    auto render() -> void override;
    auto registerAction(Action action, sf::Keyboard::Key keycode) -> void override;
    auto doAction(sf::Keyboard::Key keycode, bool isPressed) -> void override;
};