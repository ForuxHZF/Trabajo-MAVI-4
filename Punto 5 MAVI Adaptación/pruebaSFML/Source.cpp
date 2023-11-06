
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800,600), "Cambio de Tamaño de Ventana");
    

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::Resized) {// esto permitira que la resolucion no supere lo pedido (1000 x 1000) - (100 x 100)//
                int nuevoAncho = event.size.width;
                int nuevoAlto = event.size.height;

                if (nuevoAncho < 100) {
                    nuevoAncho = 100;
                }
                else if (nuevoAncho > 1000) {
                    nuevoAncho = 1000;
                }

                if (nuevoAlto < 100) {
                    nuevoAlto = 100;
                }
                else if (nuevoAlto > 1000) {
                    nuevoAlto = 1000;
                }

                window.setSize(Vector2u(nuevoAncho, nuevoAlto));
            }
        }

        window.clear();
        
        window.display();
    }

    return 0;
}
