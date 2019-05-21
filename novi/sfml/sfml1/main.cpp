#include "game.h"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"


int main()
{

    Game game;
   game.run();

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        throw std::runtime_error("Cannot open file cb.bmp!");



    sf::CircleShape circle;
    circle.setRadius(50.f);
    circle.setOutlineThickness(5.f);
    circle.setTexture(&texture);
    circle.setOutlineColor(sf::Color::White);
    circle.setOrigin(25.f,25.f);
   circle.setPosition(window.getSize().x/2.f,window.getSize().y/2.f);


    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite

        window.draw(circle);
        // Update the window
         window.display();
    }


    return 0;
}
