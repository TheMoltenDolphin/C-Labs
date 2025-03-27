#include <SFML/Graphics.hpp>
#include <math.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Chessboard");
    window.setFramerateLimit(120);
    sf::RectangleShape BoardSquares[8][8];
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            BoardSquares[i][j].setSize({128.f, 128.f});
            BoardSquares[i][j].setOrigin(64.f, 64.f);
            BoardSquares[i][j].setFillColor((i+j) % 2 == 0 ? sf::Color(212, 191, 152) : sf::Color::Black);
            BoardSquares[i][j].setPosition(128*i + 64, 128*j + 64);
        }
    }
    short WindowSizeX = window.getSize().x;
    short WindowSizeY = window.getSize().y;
    sf::CircleShape shape(WindowSizeY  / 8);

    sf::Event event;

    
    while(window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::Resized)
            {
                continue;
            }
        }
        window.clear();
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                window.draw(BoardSquares[i][j]);
        window.display();
    }
    return 0;
}