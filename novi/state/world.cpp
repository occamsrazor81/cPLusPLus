#include "world.h"
#include <ctime>
#include <random>
#include <iostream>

// Implementacija klase World dolazi ovdje.

int World::j=0;

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

 int provjera=1;
        if(x!=0 && x!=mWindowSize.x/mBlockSize-1 && y!=0 && y!=mWindowSize.y/mBlockSize-1)
        {
            for(int k=0; k<j+1; ++k)
            {
                int wx,wy;
                wx=mWall[k].getPosition().x/mBlockSize;
                wy=mWall[k].getPosition().y/mBlockSize;

                if(x==wx && y==wy) provjera=0;
            }
            if(provjera) break;
        }
    }

    mApple.setPosition(x*mBlockSize,y*mBlockSize);



}

void World::respawnWall()
{
    int x,y;
    for(int i; ;++i)
    {
        x=rand()%mWindowSize.x/mBlockSize;
        y=rand()%mWindowSize.y/mBlockSize;


        if(x!=0 && x!=mWindowSize.x/mBlockSize-1 && y!=0 && y!=mWindowSize.y/mBlockSize-1)
            break;
    }

     mWall[j].setSize({mBlockSize,mBlockSize});
     mWall[j].setFillColor(sf::Color::Yellow);
     mWall[j].setPosition(x*mBlockSize,y*mBlockSize);
     j++;
}



void World::update(Snake &snake)
{
    int p = 0;

    int jx,jy;

        jx=mApple.getPosition().x/mBlockSize;
        jy=mApple.getPosition().y/mBlockSize;




    if(snake.getPosition().x==jx &&
        snake.getPosition().y==jy)
    {snake.extend(); snake.increaseScore();
        std::cout<<snake.getScore()<<std::endl; respawnApple(); respawnWall(); }


    for(int i=0; i<4; ++i)
    {
//        if(snake.getPosition().x==0 || snake.getPosition().x==mWindowSize.x/mBlockSize - 1
//         || snake.getPosition().y==0 || snake.getPosition().y==mWindowSize.y/mBlockSize - 1)
//        {
//            snake.lose();
//            break;


//        }

        if(snake.getPosition().x==0)
            snake.setPositionx(mWindowSize.x/mBlockSize-2);

        if(snake.getPosition().x==mWindowSize.x/mBlockSize - 1)
            snake.setPositionx(1);


        if(snake.getPosition().y==0)
            snake.setPositiony(mWindowSize.y/mBlockSize-2);


        if( snake.getPosition().y==mWindowSize.y/mBlockSize - 1)
             snake.setPositiony(1);



        for(int k=0;k<j+1;++k)
        {
            int wx,wy;
            wx=mWall[k].getPosition().x/mBlockSize;
            wy=mWall[k].getPosition().y/mBlockSize;
            if( snake.getPosition().x==wx && snake.getPosition().y==wy)
            {
                snake.lose();
                p = 1;
                break;
            }
        }

    }

    if(p) for(int k=0;k<j+1;++k)
        mWall[k].setPosition(0,0);




}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int i=0; i<4; ++i)
      target.draw(mBounds[i]);
    target.draw(mApple);


    for(int k=0; k<j+1; ++k)
        target.draw(mWall[k]);

}

// Implementacija World klase.
