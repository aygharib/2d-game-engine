#pragma once

#include "Scene.h"

#include <memory>
#include <SFML/Window/Keyboard.hpp>


class Scene_Splash : public Scene {
private:
    enum class Action {
        GO_TO_PLAY
    };

    std::map<int, Action> actionMap{};
    sf::Texture texture;
    sf::Sprite sprite;
    int duration{180}; // intended duration for splash screen in frames
public:
    Scene_Splash(GameEngine* gameEngine);

    auto update() -> void override;
    auto render() -> void override;
    auto registerAction(sf::Keyboard::Key keycode, Action action) -> void;
    auto doAction(sf::Event event) -> void override;

    auto hasRegisteredAction(sf::Keyboard::Key keycode) -> bool;
};