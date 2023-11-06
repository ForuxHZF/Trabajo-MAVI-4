
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture_1;

Sprite sprite_1;


int main() {
    texture_1.loadFromFile("crosshair.png");

    sprite_1.setTexture(texture_1);
    sprite_1.setScale(0.6, 0.6);
    sprite_1.setPosition(360, 260);

    sf::RenderWindow App(sf::VideoMode(800, 600), "Punto de mira");

    while (App.isOpen()) {
        Event evt;
        while (App.pollEvent(evt)) {
            switch (evt.type) {
            case sf::Event::Closed:
                App.close();
                break;
            }
        }

        
        App.clear();
        App.draw(sprite_1);

        
        App.display();
    }

    return 0;
}
