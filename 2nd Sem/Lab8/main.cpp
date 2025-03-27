#include <SFML/Graphics.hpp>
#include <math.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    window.setFramerateLimit(120);
    short WindowSizeX = window.getSize().x;
    short WindowSizeY = window.getSize().y;
    sf::CircleShape shape(WindowSizeY  / 8);
    sf::RectangleShape rect(sf::Vector2f(WindowSizeY / 4, WindowSizeY / 4));
    sf::CircleShape octagon(WindowSizeY / 8, 8);
    octagon.setOrigin(WindowSizeY / 8, WindowSizeY / 8);
    rect.setOrigin(rect.getSize().x / 2, rect.getSize().y / 2);
    shape.setOrigin(shape.getRadius(), shape.getRadius());

    rect.setPosition(WindowSizeX / 4, WindowSizeY / 2);
    shape.setPosition(WindowSizeX / 2, WindowSizeY / 2);
    octagon.setPosition(WindowSizeX * 3 / 4, WindowSizeY / 2);

    shape.setFillColor(sf::Color::Red);
    rect.setFillColor(sf::Color::Green);
    octagon.setFillColor(sf::Color::Blue);

    bool DoMove = false;
    float speed = 0.f;
    while (window.isOpen())
    {
        speed += 0.01f;
        if(DoMove)
        {
            shape.move(0.0f, -sin(speed)*2);
            shape.rotate(1.0f);
            rect.rotate(2.0f);
            octagon.rotate(5.0f);
        }

        sf::Vector2 mousePos = sf::Mouse::getPosition(window);
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    if (shape.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        shape.setFillColor(sf::Color::Yellow);
                    }
                    if (rect.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        rect.setFillColor(sf::Color::Cyan);
                    }
                    if (octagon.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        octagon.setFillColor(sf::Color::Magenta);
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {    
                shape.setFillColor(sf::Color::Red);
                rect.setFillColor(sf::Color::Green);
                octagon.setFillColor(sf::Color::Blue);
            }
            if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                DoMove = !DoMove;
            }
        }

        window.clear();
        window.draw(shape);
        window.draw(rect);
        window.draw(octagon);
        window.display();
    }

    return 0;
}