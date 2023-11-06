//PARA REALIZAR ESTE PUNTO ME AYUDE DE GOOGLE - CHATGPT Y VIDEOS//

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture_1;
Texture texture_2;
Texture texture_3;
Texture texture_4;

Sprite sprite_1;
Sprite sprite_2;
Sprite sprite_3;
Sprite sprite_4;

int main() {
    RenderWindow App(VideoMode(800, 600), "Mover circulos - Drag");

    texture_1.loadFromFile("rcircle.png");
    texture_2.loadFromFile("rcircle.png");
    texture_3.loadFromFile("rcircle.png");
    texture_4.loadFromFile("rcircle.png");

    sprite_1.setTexture(texture_1);
    sprite_2.setTexture(texture_2);
    sprite_3.setTexture(texture_3);
    sprite_4.setTexture(texture_4);

    sprite_1.setPosition(674, 0);
    sprite_2.setPosition(674, 472);
    sprite_3.setPosition(0, 472);
    sprite_4.setPosition(-1, -1);

    Sprite sprites[] = { sprite_1, sprite_2, sprite_3, sprite_4 };
    Sprite* selectedSprite = nullptr;

    while (App.isOpen()) {
        Event event;
        while (App.pollEvent(event)) {
            if (event.type == Event::Closed)
                App.close();
            else if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                for (Sprite& sprite : sprites) {
                    if (sprite.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y))) {
                        selectedSprite = &sprite;
                    }
                }
            }
            else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                selectedSprite = nullptr;
            }
        }

        if (selectedSprite) {
            Vector2i mousePosition = Mouse::getPosition(App);
            selectedSprite->setPosition(static_cast<Vector2f>(mousePosition));
        }

        App.clear();
        for (const Sprite& sprite : sprites) {
            App.draw(sprite);
        }

        App.display();
    }

    return 0;
}