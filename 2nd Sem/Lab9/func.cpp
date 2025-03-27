#include "main.h"

void SetDict(std::map<char, sf::Texture>& dict)
{
    std::string pieces[12] = {"pawn-b", "pawn-w", "rook-b", "rook-w", "knight-b", "knight-w", "bishop-b", "bishop-w", "queen-b", "queen-w", "king-b", "king-w"};
    char piecesChar[12] = {'p', 'P', 'r', 'R', 'n', 'N', 'b', 'B', 'q', 'Q', 'k', 'K'};
    for(int i = 0; i < 12; i++)
    {
        sf::Texture texture;
        texture.loadFromFile("sprites/" + pieces[i] + ".png");
        dict[piecesChar[i]] = texture;
    }
}

void SetBoard(char board[8][8], std::vector<figure>& figures, std::map<char, sf::Texture>& dict)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] != ' ')
            {
                figure fig;
                fig.x = j;
                fig.y = i;
                sf::Sprite sprite;
                sprite.setTexture(dict[board[i][j]]);
                sprite.setOrigin(64.f, 64.f);  
                sprite.setPosition(128*j + 64, 128*i + 64);
                fig.sprite = sprite;
                figures.push_back(fig);
            }
        }
    }
}
