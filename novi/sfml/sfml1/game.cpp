#include "game.h"
#include <stdexcept>

Game::Game() : mWindow(sf::VideoMode(800, 800), "SFML window")
{
    mVelocity = 100;
    mDt = sf::seconds(1.0/60);
    mUp = mDown = mLeft = mRight = false;
    if (!mTexture.loadFromFile("SunRed.png"))
        throw std::runtime_error("Cannot open file sunred!");
    mSprite.setTexture(mTexture);
    mSprite.setOrigin(400.f,400.f);
    mSprite.setPosition(mWindow.getSize().x/2.f,mWindow.getSize().y/2.f);
    mSprite.scale(0.1f,0.1f);


    if (!mTexture1.loadFromFile("planet1.png"))
        throw std::runtime_error("Cannot open file planet1!");
    mSprite1.setTexture(mTexture1);
    mSprite1.setOrigin(250.f,250.f);
    mSprite1.setPosition(400.f,650.f);
    mSprite1.scale(0.1f,0.1f);


    if (!mTexture2.loadFromFile("Plane.png"))
        throw std::runtime_error("Cannot open file plane!");
    mSprite2.setTexture(mTexture2);
    mSprite2.setOrigin(443/2.f,302/2.f);

    mSprite2.setPosition(400.f,550.f);
    mSprite2.scale(0.1f,0.1f);

}

void Game::run()
{

    sf::Clock clock;
    sf::Time timeSinceLastUpdate=sf::Time::Zero;


    while(mWindow.isOpen())
    {
       // sf::Time dt = clock.restart();
        processEvents();
        timeSinceLastUpdate +=clock.restart();

        while(timeSinceLastUpdate > mDt)
        {
            processEvents();
            update(mDt);
            timeSinceLastUpdate -= mDt;
        }
        render();
    }

}




void Game::processEvents()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {

        switch(event.type)
        {
        case sf::Event::Closed:
        mWindow.close();
        break;

        case sf::Event::KeyPressed:
            handleUserInput(event.key.code, true);
            //if(event.key.code == sf::Keyboard::Up)
        break;

        case sf::Event::KeyReleased:
            handleUserInput(event.key.code, false);
        break;}






    }




}


void Game::render()
{
    mWindow.draw(mSprite1);
    // Clear screen
    mWindow.clear();
    // Draw the sprite
    mWindow.draw(mSprite);

     mWindow.draw(mSprite1,t);
     mWindow.draw(mSprite2,t*t1);

    // Update the window
   mWindow.display();


}

void Game::handleUserInput(sf::Keyboard::Key code, bool isPressed)
{
    if(code == sf::Keyboard::Up)
        mUp = isPressed;

    if(code == sf::Keyboard::Down)
        mDown = isPressed;

    if(code == sf::Keyboard::Right)
        mRight = isPressed;

    if(code == sf::Keyboard::Left)
        mLeft = isPressed;

}


void Game::update(sf::Time dt)
{



//        sf::Vector2f movement(0,0);
//        if(mUp) movement.y-=mVelocity;
//        if(mDown) movement.y+=mVelocity;
//        if(mRight) movement.x+=mVelocity;
//        if(mLeft) movement.x-=mVelocity;




        t.rotate(2*M_PI/60,mSprite.getPosition());
        mSprite1.rotate(2*M_PI/12);


        t1.rotate(2*M_PI/2,mSprite1.getPosition());
        mSprite2.setRotation(M_PI/2);







    //mSprite1.move(movement*dt.asSeconds());



}
