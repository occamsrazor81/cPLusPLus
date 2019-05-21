#ifndef AUX_STATES_H
#define AUX_STATES_H

#include "game.h"
#include "game_state.h"
#include "playing_state.h"

// Sva pomoćna stanja (osim PlayingState). Njihove implementacije
// su prilično slične pa ih možemo grupirati u jedan file.
class HighScoreState : public GameState{
public:
   HighScoreState(Game * game);
    virtual void update(sf::Time dt) override;
    virtual void handlePlayerInput(sf::Keyboard::Key code) override;
    virtual void render() override;


private:
    sf::Text mText;
    sf::Text mText2;
    sf::Font mFont2;

};



class WelcomeState : public GameState{
public:
    WelcomeState(Game * game);
    virtual void update(sf::Time dt) override;
    virtual void handlePlayerInput(sf::Keyboard::Key code) override;
    virtual void render() override;


private:
    sf::Text mText;
    sf::Text mText2;
    sf::Font mFont2;

};

class ExitingState : public GameState{
public:
   ExitingState(Game * game);
    virtual void update(sf::Time dt);
    virtual void handlePlayerInput(sf::Keyboard::Key code);
    virtual void render();
   float timer;




private:
    sf::Text mText;
};

class WonState : public GameState{
public:
     WonState(Game * game);
    virtual void update(sf::Time dt);
    virtual void handlePlayerInput(sf::Keyboard::Key code);
    virtual void render();




private:
    sf::Text mText;
    sf::Text mText2;
    sf::Font mFont2;

};

class LostState : public GameState{
public:
    LostState(Game * game);
    virtual void update(sf::Time dt);
    virtual void handlePlayerInput(sf::Keyboard::Key code);
    virtual void render();




private:
    sf::Text mText;
    sf::Text mText2;
    sf::Font mFont2;

};

#endif // AUX_STATES_H
