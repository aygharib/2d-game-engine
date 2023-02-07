#pragma once

#include "Scene.h"

#include <memory>
#include <SFML/Window/Keyboard.hpp>

class Scene_Splash : public Scene {
public:
    Scene_Splash(GameEngine* gameEngine);

    auto update() -> void override;
    auto render() -> void override;
    auto registerAction(sf::Keyboard::Key keycode, Action action) -> void override;
    auto doAction(Action action, bool isPressed) -> void override;
};