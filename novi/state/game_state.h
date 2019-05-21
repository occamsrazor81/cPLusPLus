#ifndef GAME_STATE_H
#define GAME_STATE_H

// includes ...
#include "snake.h"
#include "world.h"



class Game;  // Samo referenca da se ne uvode cirkularne zavisnosti!

class GameState{
public:
    // Sva moguća stanja igre.
    enum State {
        Welcome,
        Playing,
        Won,
        Lost,
        Exiting,
        HighScore,
        Count     // Count će dati broj stanja.
    };
    GameState(Game * game) : mpGame(game) {    if(!mFont.loadFromFile("Comfortaa-Bold.ttf"))
                throw std::runtime_error("No font named Comfortaa-Bold.ttf");}

    // Metode koje ovise o stanju.
    virtual ~GameState()=default;
    virtual void update(sf::Time dt) = 0;
    virtual void handlePlayerInput(sf::Keyboard::Key code)= 0;
    virtual void render() = 0;

    void setScore(int score1) { score=score1; }
     void setHighScore(int score1) { hscore=score1; }
    int getScore() { return score;}


protected:
    Game * mpGame;
    int score;
    int hscore;

    sf::Font mFont;
};

#endif // GAME_STATE_H
