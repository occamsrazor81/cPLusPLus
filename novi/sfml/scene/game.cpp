#include "game.h"

// Implementacija klase Game.


#include "game.h"
#include "sceneGraph.h"
#include <stdexcept>

// Implementacija klase Game.

Game::Game():mWindow (sf::VideoMode(640,480),"Avioni"),mWorld(mWindow)
{
    mWindow.setVerticalSyncEnabled(true);
    mTimePerFrame=sf::seconds(1.0/60);
    delta.x=0;
    delta.y=0;
}

void Game::run()
{
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
                   update(mTimePerFrame);
                }
          render();
      }

}

void Game::processEvents()
{
    sf::Event event;

    bool moving = false;
   sf::Vector2f oldPos(0.f,0.f);

       while(mWindow.pollEvent(event))
       {
           switch(event.type){
                   case sf::Event::Closed:
                       mWindow.close();

                       case sf::Event::MouseButtonPressed:

                               moving=true;

                           oldPos=mWindow.mapPixelToCoords( sf::Vector2i(event.mouseButton.x, event.mouseButton.y) );
                               handlePlayerInput(event.mouseButton.button,moving);
                        case sf::Event::MouseButtonReleased:

                                 moving=false;


                                 handlePlayerInput(event.mouseButton.button,moving);


                      case sf::Event::MouseMoved:
                          if(moving){
                               sf::Vector2f newPos = mWindow.mapPixelToCoords( sf::Vector2i(event.mouseMove.x, event.mouseMove.y) );
                               delta = (newPos - oldPos);

                                delta /= 100.f;
                                handlePlayerInput(event.mouseButton.button,moving);
                            }

                          case sf::Event::KeyPressed:
                                mWorld.handlePlayerInput(event.key.code);






            }
       }


}

void Game::update(const sf::Time & dt)
{
        mWorld.update(dt);
}

void Game::render()
{
       mWindow.clear();


       mWorld.draw();

       mWindow.display();

}



void Game::handlePlayerInput(sf::Mouse::Button code, bool isPressed)
{
   mWorld.handlePlayerInput(code,isPressed);

}


