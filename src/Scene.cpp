#include "Scene.h"

Scene::Scene(GameEngine* gameEngine) : gameEngine(gameEngine) {}

auto Scene::hasRegisteredAction(sf::Keyboard::Key keycode) -> bool {
    return actionMap.find(keycode) != actionMap.end();
}
