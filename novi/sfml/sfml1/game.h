#ifndef GAME_H
#define GAME_H

#include<SFML/Graphics.hpp>

class Game
{
public:
    Game();
    void run();

private:
    sf::RenderWindow mWindow;
    sf::Texture mTexture;
    sf::Sprite mSprite;
    sf::Transform t;


    sf::Texture mTexture1;
    sf::Sprite mSprite1;
    sf::Transform t1;



    sf::Texture mTexture2;
    sf::Sprite mSprite2;



    float mVelocity;

    bool mUp, mDown, mLeft, mRight;

    sf::Time mDt;

    void  processEvents();
    void update(sf::Time dt);
    void render();

    void handleUserInput(sf::Keyboard::Key key, bool isPressed);




};





















#endif // GAME_H

