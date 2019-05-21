#include "world.h"
#include <ctime>
#include <random>
#include <iostream>

// Implementacija klase World dolazi ovdje.



World::World(sf::Vector2i windowSize):mWindowSize(windowSize)
{

    mBlockSize=20;
    mApple.setRadius(10);

    mApple.setFillColor(sf::Color::Red);
    mBounds[0].setSize({mBlockSize,mWindowSize.y});
     mBounds[1].setSize({mWindowSize.y,mBlockSize});
     mBounds[2].setSize({mBlockSize,mWindowSize.x});
     mBounds[3].setSize({mWindowSize.y,mBlockSize});

     mBounds[2].setPosition({mWindowSize.x-mBlockSize,0});
    mBounds[3].setPosition({0,mWindowSize.y-mBlockSize});


    for(int i=0;i<4;++i)
    {
        mBounds[i].setFillColor(sf::Color::Transparent);
        mBounds[i].setOutlineColor(sf::Color::Yellow);
        mBounds[i].setOutlineThickness(5);
    }



    respawnApple();



}

void World::respawnApple()
{
    int x,y;
   for(int i=0; ;++i)
    {
        x=rand()%mWindowSize.x/mBlockSize;
        y=rand()%mWindowSize.y/mBlockSize;

        if(x!=0 && x!=mWindowSize.x/mBlockSize-1 && y!=0 && y!=mWindowSize.y/mBlockSize-1)
            break;
    }

    mApple.setPosition(x*mBlockSize,y*mBlockSize);



}



void World::update(Snake &snake)
{

    int jx,jy;

        jx=mApple.getPosition().x/mBlockSize;
        jy=mApple.getPosition().y/mBlockSize;




    if(snake.getPosition().x==jx &&
        snake.getPosition().y==jy)
    {snake.extend(); snake.increaseScore(); respawnApple(); std::cout<<snake.getScore()<<std::endl; }



    for(int i=0; i<4; ++i)
    {
        if(snake.getPosition().x==0 || snake.getPosition().x==mWindowSize.x/mBlockSize - 1
         || snake.getPosition().y==0 || snake.getPosition().y==mWindowSize.y/mBlockSize - 1)
            snake.reset();
        break;
    }





}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int i=0; i<4; ++i)
      target.draw(mBounds[i]);
    target.draw(mApple);

}


