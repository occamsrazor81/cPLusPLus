#ifndef PLAYING_STATE_H
#define PLAYING_STATE_H

#include "game_state.h"
#include "game.h"
#include "snake.h"
#include "world.h"

// Naša glavna state-klasa. Veći dio koda iz
// prethodne Game klase završit će ovdje s manjim izmjenama.
class PlayingState : public GameState{
public:
    PlayingState(Game* game);
    virtual void update(sf::Time dt);
    virtual void handlePlayerInput(sf::Keyboard::Key code);
    virtual void render();



private:
    Snake mSnake;
    World mWorld;
    bool updated;
    sf::Time timeSinceLastUpdate;
    sf::Time timePerFrame;


};


#endif // PLAYING_STATE_H
