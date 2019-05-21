#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "sceneGraph.h"

class Game{
public:
    Game();
    void run();
private:
    // Procesiraj događaje
    void processEvents();
    // konstruiraj novo stanje igre
    void update(sf::Time const &);
    // iscrtaj novo stanje
    void render();
    sf::Vector2f delta;
private:

    void handlePlayerInput(sf::Mouse::Button code, bool isPressed);

    sf::RenderWindow mWindow;
    sf::Time mTimePerFrame;
    World mWorld;

};

#endif
