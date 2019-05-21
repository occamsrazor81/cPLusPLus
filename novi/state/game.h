#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <array>
#include <stack>
#include "game_state.h"

// Klasa koja predstavlja igru.
class Game{
public:
    Game();
    ~Game();
    void run();
    void changeState(GameState::State newState)
    { mpCurrentGameState =mpGameStates[newState]; }

    GameState* GetState (GameState::State state) { return mpGameStates[state];}
    void speedUp (bool provjera) { if(provjera) mTimePerFrame=mTimePerFrame.asSeconds()*sf::seconds(1.f/2.f);}


    //void quit() { gameRunning=false; }
    sf::RenderWindow* GetWindow() {return &mWindow;}

    // ostali dio sučelja
private:
    void processEvents();
    sf::RenderWindow mWindow;
    sf::Time         mTimePerFrame;
    // trenutno stanje igre određeno je ovim pokazivačem.
    GameState *      mpCurrentGameState;
    // Sva stanja igre. GameState::Count daje broj stanja.

    // ostale privatne varijable
    // eventualne friend deklaracije




     std::array<GameState*,GameState::Count> mpGameStates;
  // std::stack<GameState*> mpGameStates;
    bool gameRunning;
};

#endif // GAME-V1_H_INCLUDED
