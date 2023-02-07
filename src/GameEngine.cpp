#include "GameEngine.h"

#include <memory>
#include <string>
#include <iostream>
#include <SFML/Window/Event.hpp>

GameEngine::GameEngine() : running{true} {
    window.create(sf::VideoMode(1280, 720), "2D Game Engine");
    window.setFramerateLimit(60);
}

auto GameEngine::run() -> void {
    while (window.isOpen()) {
        update();

        scene.render();

        window.display();
    }
}

auto GameEngine::update() -> void {
    sUserInput();

    scene.update();
}

auto GameEngine::quit() -> void {
    running = false;
    window.close();
}

auto GameEngine::sUserInput() -> void {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            quit();
        }
        
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            if (scene.actionMap.find(event.key.code) == scene.actionMap.end()) {
                continue;
            }

            auto isPressed = (event.type == sf::Event::KeyPressed) ? true : false;
            scene.doAction(scene.actionMap.at(event.key.code), isPressed);
        }
    }
}