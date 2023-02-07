#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <memory>
#include <string>
#include <vector>

#include "Scene.h"

class GameEngine {
public:
    bool running;
    int currentScene{0};
    std::vector<std::shared_ptr<Scene>> scenes{};
    sf::RenderWindow window;

    auto run()    -> void;
    auto update() -> void;
    auto render() -> void;
    auto quit()   -> void;

    auto userInput() -> void;

    auto getCurrentScene() -> std::shared_ptr<Scene>;
    auto setCurrentScene(int currentScene) -> void;

    GameEngine();
};
