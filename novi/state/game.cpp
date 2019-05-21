#include "game.h"
#include "game_state.h"
#include "aux_states.h"

// Implementacija Game klase

Game::Game() :mWindow(sf::VideoMode{800,800}, "Snek game")
{
   // Ovdje alocirati sva stanja i postaviti pokazivač na trenutno stanje

    mpGameStates[0]= new WelcomeState(this);
    mpGameStates[1]= new PlayingState(this);
    mpGameStates[2]= new WonState(this);
    mpGameStates[3]= new LostState(this);
    mpGameStates[4]= new ExitingState(this);
    mpGameStates[5]= new HighScoreState(this);

    mpCurrentGameState=mpGameStates[0];

     mTimePerFrame=sf::seconds(1.f/20.f);







}

Game::~Game()
{
    for(std::size_t i=0;i<GameState::State::Count; ++i)
        delete mpGameStates[i];

}



// Primjer run - metode. Zavisni dijelovi koda se delegiraju GameState klasama
// kroz pokazivač mpCurrentGameState.
void Game::run(){
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while(mWindow.isOpen())
    {
       processEvents();
       timeSinceLastUpdate += clock.restart();
       while(timeSinceLastUpdate > mTimePerFrame)
       {
          timeSinceLastUpdate -= mTimePerFrame;
          processEvents();
          mpCurrentGameState->update(mTimePerFrame);
       }
       // rendering
       mWindow.clear();
       mpCurrentGameState->render();
       mWindow.display();
    }
}




// obrada događaja
void Game::processEvents(){
   // implementacija
    sf::Event event;
            while(mWindow.pollEvent(event))
            {

                if(event.type == sf::Event::Closed )
                    mWindow.close();

                if(event.type==sf::Event::KeyPressed)
                {mpCurrentGameState->handlePlayerInput(event.key.code); break;}

            }



}
