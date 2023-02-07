#include "GameEngine.h"
#include "Scene_Play.h"
#include "Scene_Splash.h"

#include <memory>
#include <string>
#include <iostream>
#include <SFML/Window/Event.hpp>

GameEngine::GameEngine() : running{true} {
    window.create(sf::VideoMode(1280, 720), "2D Game Engine");
    window.setFramerateLimit(60);

    scenes.push_back(std::make_shared<Scene_Splash>(this));
    scenes.push_back(std::make_shared<Scene_Play>(this));
}

auto GameEngine::run() -> void {
    while (window.isOpen()) {
        update();
        render();
    }
}

auto GameEngine::update() -> void {
    userInput();

    getCurrentScene()->update();
}

auto GameEngine::render() -> void {
    // Clear Screen
    window.clear(sf::Color::Black);

    getCurrentScene()->render();
 
    window.display();
}

auto GameEngine::quit() -> void {
    running = false;
    window.close();
}

auto GameEngine::userInput() -> void {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            quit();
        }
        
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            // Do not invoke action if the action is not registered for the scene
            if (!getCurrentScene()->hasRegisteredAction(event.key.code)) {
                continue;
            }

            auto isPressed = (event.type == sf::Event::KeyPressed) ? true : false;
            getCurrentScene()->doAction(event.key.code, isPressed);
        }
    }
}

auto GameEngine::getCurrentScene() -> std::shared_ptr<Scene> {
    return scenes.at(currentScene);
}
auto GameEngine::setCurrentScene(int currentScene) -> void {
    this->currentScene = currentScene;
}