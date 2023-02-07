#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <map>
#include <string>

#include "Scene_Play.h"

class GameEngine {
public:
    sf::RenderWindow window;

    Scene_Play scene{this};

    bool running;

    auto run()        -> void;
    auto update()     -> void;
    auto quit()       -> void;

    auto sUserInput() -> void;

    GameEngine();
};
