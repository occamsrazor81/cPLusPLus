#include "snake.h"

//  Implementacija klase Snake dolazi ovdje.

Snake::Snake(int blockSize)
{
    mspeed=1;
    mlives=3;
    mscore=0;
    msize=blockSize;
    mdir=Direction::None;
    mlost=false;

    SnakeContainer snek;
    SnakeSegment seg1(6,5);
    SnakeSegment seg2(6,6);
    SnakeSegment seg3(6,7);
    snek.push_back(seg3);
    snek.push_back(seg2);
    snek.push_back(seg1);

    mSnakeBody=snek;




}

void Snake::reset()
{
    mSnakeBody.clear();
    mspeed=1;
    mlives=3;
    mscore=0;

    mdir=Direction::None;
    mlost=false;


    SnakeContainer snek;
    SnakeSegment seg1(10,10);
    SnakeSegment seg2(10,11);
    SnakeSegment seg3(10,12);
    snek.push_back(seg3);
    snek.push_back(seg2);
    snek.push_back(seg1);

    mSnakeBody=snek;






}


sf::Vector2i Snake::getPosition()
{
    sf::Vector2i loc;
    loc.x=mSnakeBody[0].x;
    loc.y=mSnakeBody[0].y;
            return loc;

}

void Snake::extend()
{
   mSnakeBody.push_back(mSnakeBody[mSnakeBody.size()-1]);
}

void Snake::move()
{

    if(mdir==Direction::Down)
    {
        mSnakeBody.insert(mSnakeBody.begin(),
               SnakeSegment(mSnakeBody.front().x,mSnakeBody.front().y+mspeed));
        mSnakeBody.pop_back();


    }


    if(mdir==Direction::Left)
    {
        mSnakeBody.insert(mSnakeBody.begin(),
               SnakeSegment(mSnakeBody.front().x-mspeed,mSnakeBody.front().y));
        mSnakeBody.pop_back();

    }


    if(mdir==Direction::Right)
    {
        mSnakeBody.insert(mSnakeBody.begin(),
               SnakeSegment(mSnakeBody.front().x+mspeed,mSnakeBody.front().y));
        mSnakeBody.pop_back();

    }


    if(mdir==Direction::Up)
    {
        mSnakeBody.insert(mSnakeBody.begin(),
               SnakeSegment(mSnakeBody.front().x,mSnakeBody.front().y-mspeed));
        mSnakeBody.pop_back();

    }



}

void Snake::update()
{
    move();
    checkCollision();

}

void Snake::checkCollision()
{
    for(int i=1; i<mSnakeBody.size();++i)
    if(mSnakeBody.front().x==mSnakeBody[i].x && mSnakeBody.front().y==mSnakeBody[i].y )
    {
        mlives--;
        if(!mlives) reset();
       else cut(mSnakeBody.size()-i);

    }



}

void Snake::draw(sf::RenderTarget &target, sf::RenderStates states) const
{

    mbodyRect.setSize({msize,msize});
    mbodyRect.setFillColor(sf::Color::Blue);
    mbodyRect.setOutlineColor(sf::Color::Black);
    mbodyRect.setOutlineThickness(3);
    int x=mSnakeBody[0].x*msize;
    int y=mSnakeBody[0].y*msize;
    mbodyRect.setPosition(x,y);

    target.draw(mbodyRect);

    for(int i=1;i < mSnakeBody.size(); ++i)
    {
//        if(i%3==1)mbodyRect.setFillColor(sf::Color::Red);
//         if(i%3==2)mbodyRect.setFillColor(sf::Color::White);
//          if(i%3==0)mbodyRect.setFillColor(sf::Color::Blue);

        if(i%2==1)mbodyRect.setFillColor(sf::Color::White);
        if(i%2==0)mbodyRect.setFillColor(sf::Color::Red);
        x=mSnakeBody[i].x*msize;
        y=mSnakeBody[i].y*msize;

        mbodyRect.setPosition(x,y);
        target.draw(mbodyRect);
    }

}

void Snake::cut(int n)
{

   for(int i=0;i<n;++i)
       mSnakeBody.pop_back();

}


