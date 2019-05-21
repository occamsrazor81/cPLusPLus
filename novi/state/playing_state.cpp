#include "playing_state.h"

// Implementacija PlayingState klase

PlayingState::PlayingState(Game* game) :mSnake(20), mWorld({800,800}), GameState(game)//,score(0)
{





}

void PlayingState::update(sf::Time dt)
{





    mSnake.update();
    mWorld.update(mSnake);



    if(mSnake.hasLost())
            {

                mpGame->GetState(GameState::State::Won)->setScore(mSnake.getScore());
                mpGame->GetState(GameState::State::Lost)->setScore(mSnake.getScore());
                mpGame->GetState(GameState::State::HighScore)->setScore(mSnake.getScore());
                mpGame->GetState(GameState::State::Playing)->setScore(mSnake.getScore());

                 if(mpGame->GetState(GameState::State::Playing)->getScore() > hscore)
                 {
                     mpGame->GetState(GameState::State::Won)->setHighScore(mSnake.getScore());
                     mpGame->GetState(GameState::State::Lost)->setHighScore(mSnake.getScore());
                     mpGame->GetState(GameState::State::HighScore)->setHighScore(mSnake.getScore());
                     mpGame->GetState(GameState::State::Playing)->setHighScore(mSnake.getScore());
                 }

                if(score>=100)
                {


                   // mpGame->speedUp(true);
                    mpGame->changeState(GameState::State::Won);
                }
                else
                {
                   // mpGame->speedUp(false);
                    mpGame->changeState(GameState::State::Lost);
                }
                mSnake.reset();
            }


}

void PlayingState::handlePlayerInput(sf::Keyboard::Key code)
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

void PlayingState::render()
{


    sf::RenderWindow* window=mpGame->GetWindow();
    window->clear();
    window->draw(mSnake);
    window->draw(mWorld);
    window->display();


}
