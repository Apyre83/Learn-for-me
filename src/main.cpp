#include <SFML/Graphics.hpp>

int main()
{
    // Create a window with the title "SFML Test"
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

    // Create a circle shape with radius of 50
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);

    // Main loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw the circle shape
        window.draw(shape);

        // Display the contents of the window
        window.display();
    }

    return 0;
}