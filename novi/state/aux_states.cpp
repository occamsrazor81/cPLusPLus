#include "aux_states.h"
#include <iostream>
#include <string>

// Implementacija pomoćnih stanja.


WelcomeState::WelcomeState(Game * game) :GameState(game)
{
    if(!mFont2.loadFromFile("Broken-Heart.ttf"))
                    throw std::runtime_error("Broken-Heart.ttf");


   mText.setFont(mFont2);
   mText.setColor(sf::Color::Cyan);
   mText.setString("Snek game \n     by Ivan Knezic");
   mText.setCharacterSize(64);
   mText.setOrigin(mText.getLocalBounds().width/2,mText.getLocalBounds().height/2);
   mText.setPosition(400,400);

   mText2.setFont(mFont2);
   mText2.setColor(sf::Color::Cyan);
   mText2.setString("Hit any key to continue\nH to HighScore");
   mText2.setCharacterSize(32);
   mText2.setOrigin(mText.getLocalBounds().width/2,mText.getLocalBounds().height/2);
   mText2.setPosition(700,700);


}

void WelcomeState::update(sf::Time dt)
{


}

void WelcomeState::handlePlayerInput(sf::Keyboard::Key code)
{
    if(code==sf::Keyboard::H)
        mpGame->changeState(HighScore);


    else
      mpGame->changeState(Playing);



}

void WelcomeState::render()
{

    sf::RenderWindow* window=mpGame->GetWindow();
    window->clear();
    window->draw(mText);
    window->draw(mText2);
    window->display();

}





WonState::WonState(Game *game) :GameState(game)
{

    if(!mFont2.loadFromFile("Broken-Heart.ttf"))
                        throw std::runtime_error("Broken-Heart.ttf");

    mText.setFont(mFont);




}

void WonState::update(sf::Time dt)
{

}

void WonState::handlePlayerInput(sf::Keyboard::Key code)
{
    if(code==sf::Keyboard::C)
        mpGame->changeState(Playing);

    if(code==sf::Keyboard::X)
        mpGame->changeState(Exiting);

    if(code==sf::Keyboard::H)
        mpGame->changeState(HighScore);
}

void WonState::render()
{

    mText.setColor(sf::Color::Cyan);
    mText.setString("You won \n  The score = "+std::to_string(score));


    mText.setCharacterSize(64);
    mText.setOrigin(mText.getLocalBounds().width/2,mText.getLocalBounds().height/2);
    mText.setPosition(400,400);

    mText2.setFont(mFont);
    mText2.setColor(sf::Color::Cyan);
    mText2.setString("Hit C to continue, X to exit \nH to HighScore");
    mText2.setCharacterSize(32);
    mText2.setOrigin(mText.getLocalBounds().width/2,mText.getLocalBounds().height/2);
    mText2.setPosition(600,700);
    sf::RenderWindow* window=mpGame->GetWindow();

    window->clear();
    window->draw(mText);
    window->draw(mText2);
    window->display();



}

LostState::LostState(Game *game) :GameState(game)
{

    if(!mFont2.loadFromFile("Broken-Heart.ttf"))
                        throw std::runtime_error("Broken-Heart.ttf");

    mText.setFont(mFont);



}

void LostState::update(sf::Time dt)
{

}

void LostState::handlePlayerInput(sf::Keyboard::Key code)
{
    if(code==sf::Keyboard::C)
        mpGame->changeState(Playing);

    if(code==sf::Keyboard::X)
        mpGame->changeState(Exiting);

    if(code==sf::Keyboard::H)
        mpGame->changeState(HighScore);


}

void LostState::render()
{
    mText.setColor(sf::Color::Cyan);

    mText.setString("You lost \n  The score = "+std::to_string(score));
    mText.setCharacterSize(64);
    mText.setOrigin(mText.getLocalBounds().width/2,mText.getLocalBounds().height/2);
    mText.setPosition(400,400);

    mText2.setFont(mFont2);
    mText2.setColor(sf::Color::Cyan);
    mText2.setString("Hit C to continue, X to exit,\nH to HighScore");
    mText2.setCharacterSize(32);
    mText2.setOrigin(mText.getLocalBounds().width/2,mText.getLocalBounds().height/2);
    mText2.setPosition(600,700);



    sf::RenderWindow* window=mpGame->GetWindow();

    window->clear();
    window->draw(mText);
    window->draw(mText2);
    window->display();

}

ExitingState::ExitingState(Game *game) :GameState(game)
{
    timer=0;

   mText.setFont(mFont);




}

void ExitingState::update(sf::Time dt)
{


    timer += dt.asSeconds();
           if( timer < 1.0 )
           {
               mText.setString("Game over 3");
           }
           else if (timer > 1.0 && timer < 2.0 )
           {
               mText.setString("Game over 2");
           }
           else if (timer > 2.0 && timer < 3.0)
           {
               mText.setString("Game over 1");
           }

        else
        {
            sf::RenderWindow* window =mpGame->GetWindow();
            window->close();
        }
}



void ExitingState::handlePlayerInput(sf::Keyboard::Key code)
{


}

void ExitingState::render()
{

    mText.setColor(sf::Color::Cyan);
       mText.setCharacterSize(64);
       mText.setOrigin(mText.getLocalBounds().width/2.f,mText.getLocalBounds().height/2.f);
       mText.setPosition(400,400);



    sf::RenderWindow* window=mpGame->GetWindow();

    window->clear();
    window->draw(mText);
    window->display();


}

HighScoreState::HighScoreState(Game *game) :GameState(game)
{

    if(!mFont2.loadFromFile("Broken-Heart.ttf"))
                    throw std::runtime_error("Broken-Heart.ttf");
    mText.setFont(mFont);
}

void HighScoreState::update(sf::Time dt)
{

}

void HighScoreState::handlePlayerInput(sf::Keyboard::Key code)
{

    if(code==sf::Keyboard::C)
        mpGame->changeState(Playing);

    if(code==sf::Keyboard::X)
        mpGame->changeState(Exiting);

    if(code==sf::Keyboard::W)
        mpGame->changeState(Welcome);



}

void HighScoreState::render()
{
    mText.setColor(sf::Color::Cyan);
    mText.setString("high score = "+std::to_string(hscore));
    mText.setCharacterSize(64);
    mText.setOrigin(mText.getLocalBounds().width/2,mText.getLocalBounds().height/2);
    mText.setPosition(400,400);

    mText2.setFont(mFont2);
    mText2.setColor(sf::Color::Cyan);
    mText2.setString("Hit C to continue, X to exit,\nW to WeclomeScreen");
    mText2.setCharacterSize(32);
    mText2.setOrigin(mText.getLocalBounds().width/2,mText.getLocalBounds().height/2);
    mText2.setPosition(600,700);


    sf::RenderWindow* window=mpGame->GetWindow();

    window->clear();
    window->draw(mText);
    window->draw(mText2);
    window->display();
}
