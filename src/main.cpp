#include "learn-for-me.h"


int main()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(desktop, "Learn for me", sf::Style::Fullscreen);
    sf::Vector2u size = window.getSize();

    const int    cellSizeX = size.x / GRID_SIZE_X;
    const int    cellSizeY = size.y / GRID_SIZE_Y;
    const int    cellOffsetX = size.x - (cellSizeX * GRID_SIZE_X);
    const int    cellOffsetY = size.y - (cellSizeY * GRID_SIZE_Y);

    std::cout << "cellSizeX: " << cellSizeX << std::endl;
    std::cout << "cellSizeY: " << cellSizeY << std::endl;
    std::cout << "cellOffsetX: " << cellOffsetX << std::endl;
    std::cout << "cellOffsetY: " << cellOffsetY << std::endl;

    Player player(std::min(cellSizeX, cellSizeY));

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        player.update(size, cellSizeX, cellSizeY, cellOffsetX, cellOffsetY);

        window.clear();

        for (int i = 0; i < GRID_SIZE_X; ++i) {
            for (int j = 0; j < GRID_SIZE_Y; ++j) {
                sf::RectangleShape cell(sf::Vector2f(cellSizeX, cellSizeY));
                cell.setPosition({i * cellSizeX + cellOffsetX * 1.0f, j * cellSizeY + cellOffsetY * 1.0f});

                cell.setFillColor(sf::Color::Black);
                cell.setOutlineThickness(2);
                cell.setOutlineColor(sf::Color::White);

                window.draw(cell);
            }
        }

        player.draw(window);

        window.display();
    }

    return 0;
}
