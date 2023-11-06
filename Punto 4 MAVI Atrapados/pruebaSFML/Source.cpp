//ME AYUDE UN POCO AFUERA DEL MATERIAL YA QUE ESTABA TENIENDO PROBLEMAS CON EL ESCALADO DE LAS IMAGENES Y LOS LIMITES DE LA PANTALLA//
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

Texture texture_1;
Texture texture_2;

Sprite sprite_1;
Sprite sprite_2;

int main() {
    sf::RenderWindow App(sf::VideoMode(800, 600), "Atrapado");

    texture_1.loadFromFile("cuad_yellow.png");
    texture_2.loadFromFile("rcircleg.png");

    sprite_1.setTexture(texture_1);
    sprite_2.setTexture(texture_2);

    sf::Vector2f position(360, 260);

    float movimiento = 20.0f;

    sf::Vector2f Scale(0.98f, 0.98f);

    sprite_1.setScale(0.228, 0.228);

    sprite_1.setPosition(position);

    while (App.isOpen()) {
        sf::Event event;

        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                App.close();
            else if (event.type == sf::Event::KeyPressed) { //Utilize un switch para nombrar las flechas de direccion y el cambio de figura // 
                switch (event.key.code) {
                case Keyboard::Left:
                    if (position.x > 0) {
                        position.x -= movimiento;
                    }
                    break;
                case Keyboard::Right:
                    if (position.x + sprite_2.getGlobalBounds().width < App.getSize().x) {
                        position.x += movimiento;
                    }
                    break;
                case Keyboard::Down:
                    if (position.y + sprite_2.getGlobalBounds().height < App.getSize().y) {
                        position.y += movimiento;
                    }
                    break;
                case Keyboard::Up:
                    if (position.y > 0) {
                        position.y -= movimiento;
                    }
                    break;
                case Keyboard::Space:
                    sprite_1.setTexture(texture_2);
                    sprite_1.setScale(Scale);
                    break;
                default:
                    break;
                }
            }
        }


        App.clear();//En el caso de no limpiar este cuadrado o circulo si lo cambiamos, ira dejando marcado su recorrido pintando la consola//
        
        sprite_1.setPosition(position);

        App.draw(sprite_1);

        App.display();
    }

    return 0;
}