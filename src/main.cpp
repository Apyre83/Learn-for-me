#include "learn-for-me.h"


/*void removeBlackBackground(sf::Texture& texture)
{
    sf::Image image = texture.copyToImage();
    for (unsigned int x = 0; x < image.getSize().x; ++x)
    {
        for (unsigned int y = 0; y < image.getSize().y; ++y)
        {
            sf::Color pixel = image.getPixel({x, y});
            if (pixel == sf::Color::Black)
            {
                pixel.a = 0;
                image.setPixel({x, y}, pixel);
            }
        }
    }
    texture.update(image);
}*/


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


	sf::Texture playerTexture;
	if (playerTexture.loadFromFile("res/player.png") == false) {
		std::cout << "Error loading player.png" << std::endl;
		return 1;
	}

	sf::Texture studentTexture;
	if (studentTexture.loadFromFile("res/student.png") == false) {
		std::cout << "Error loading student.png" << std::endl;
		return 1;
	}

	sf::Texture teacherTexture;
	if (teacherTexture.loadFromFile("res/teacher.png") == false) {
		std::cout << "Error loading teacher.png" << std::endl;
		return 1;
	}



    Player player(std::min(cellSizeX, cellSizeY), playerTexture);

	std::vector<Student> students;
	students.push_back(Student(10, 10, std::min(cellSizeX, cellSizeY), cellSizeX, cellSizeY, studentTexture));
	students.push_back(Student(5, 5, std::min(cellSizeX, cellSizeY), cellSizeX, cellSizeY, studentTexture));

	std::vector<Desk> desks;
	desks.push_back(Desk(10, 10, std::min(cellSizeX, cellSizeY), cellSizeX, cellSizeY));
	desks.push_back(Desk(5, 5, std::min(cellSizeX, cellSizeY), cellSizeX, cellSizeY));
	desks[0].setStudent(&students[0]);
	desks[1].setStudent(&students[1]);

	Teacher teacher(7, 10, std::min(cellSizeX, cellSizeY), cellSizeX, cellSizeY, teacherTexture);



	sf::Clock	clock;
	float		dt;


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

		dt = clock.restart().asSeconds();

        player.update(size, dt, students, desks);

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

		for (auto& desk : desks) {
			desk.draw(window);
		}

		teacher.draw(window);

        window.display();
    }

    return 0;
}
