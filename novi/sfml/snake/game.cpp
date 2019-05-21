#include "game.h"
#include "world.h"
#include "snake.h"
#include <iostream>
#include <SFML/Graphics.hpp>

// Implementacija Game klase dolazi ovdje.


Game::Game():mWindow(sf::VideoMode(800,800),"Snek"), mSnake(20), mWorld({800,800})
{
    mTimePerFrame=sf::seconds(1.f/3600.f);



}





void Game::run()
{

    sf::Clock clock;
    sf::Time timeSinceLastUpdate=sf::Time::Zero;


    while(mWindow.isOpen())
       {
        sf::Time dt = clock.restart();
            processEvents();
          timeSinceLastUpdate += clock.restart();

            while(timeSinceLastUpdate > mTimePerFrame )
            {
               processEvents();
                update(mTimePerFrame);
                timeSinceLastUpdate -= mTimePerFrame;
            }



            render();
       }

}

void Game::processEvents()
{

    sf::Event event;
        while(mWindow.pollEvent(event))
        {

            if(event.type == sf::Event::Closed )
                mWindow.close();

            if(event.type==sf::Event::KeyPressed)
            {handlePlayerInput(event.key.code); break;}

        }
}

void Game::update(sf::Time dt)
{

    mSnake.update();
 mWorld.update(mSnake);

}

void Game::render()
{

        // Clear screen
        mWindow.clear();
        // Draw the sprite
        mWindow.draw(mSnake);
        mWindow.draw(mWorld);

        // Update the window
        mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key code)
{



    if(code == sf::Keyboard::Up)
     if(mSnake.getDirection()!=Direction::Down)
        mSnake.setDirection(Direction::Up);



    if(code == sf::Keyboard::Left)
        if(mSnake.getDirection()!=Direction::Right)
        mSnake.setDirection(Direction::Left);

    if(code == sf::Keyboard::Right)
        if(mSnake.getDirection()!=Direction::Left)
        mSnake.setDirection(Direction::Right);

    if(code == sf::Keyboard::Down)
        if(mSnake.getDirection()!=Direction::Up)
        mSnake.setDirection(Direction::Down);

    else mSnake.setDirection(Direction::None);




}
