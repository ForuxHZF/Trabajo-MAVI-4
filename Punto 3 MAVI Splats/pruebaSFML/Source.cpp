#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;


Texture texture_1;
Texture texture_2;

Sprite sprite_1;
Sprite sprite_2;


int main()
{

    sf::RenderWindow App(sf::VideoMode(800, 600), "Splast");

    texture_1.loadFromFile("rcircle.png");
    texture_2.loadFromFile("rcircleb.png");

    
    sprite_1.setTexture(texture_1);
    sprite_2.setTexture(texture_2);


    bool viRojo = false;
    bool viAzul = false;

    while (App.isOpen())
    {
        Event event;

        while (App.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                App.close();
            {
                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    sprite_1.setPosition(x, y);
                    viRojo = true;
                } 
                {
                    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
                    {
                        int x = event.mouseButton.x;
                        int y = event.mouseButton.y;
                        sprite_2.setPosition(x, y);
                        viAzul= true;
                    }
                }
            }
        }
        if (viRojo){
            App.draw(sprite_1);

        }
        if (viAzul){
            App.draw(sprite_2);
        }

        
        App.display();
    }

    return 0;
}