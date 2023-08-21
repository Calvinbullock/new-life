#include <SFML/Graphics.hpp>

int main()
{
    float windowWidth = 400;
    float windowHeight = 400;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "NewLife");

    sf::Texture texture;
    if (texture.loadFromFile("images/slime.png"))
    {
        return 0;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

// Compile command
// g++ *FILE-NAME*.cpp -o *EXACUTABLE-NAME* -lsfml-graphics -lsfml-window -lsfml-system^C