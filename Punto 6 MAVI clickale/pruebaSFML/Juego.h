//Se me hizo muy complicado el hacer el codigo el video dejado en la pagina de la facultad de ayudo mucho .
//Igualmente tuve que recurrir a sitios externos ya que hubo cosas como el limite de eliminaciones para finalizar que lo saque de afuera del video.
//Muy buena experiencia, despues de todo estuvo entretenido ver como va avanzando, aunque fue un poco tardado.
#pragma once
#include "stdafx.h"
#include "PlayerCrosshair.h"
#include "Enemigo.h"

using namespace sf;

class Juego {
    RenderWindow* _wnd;
    PlayerCrosshair* _player;
    Enemigo* _enemigos;
    int enemigosEliminados;

public:
    Juego() {
        _wnd = new RenderWindow(VideoMode(800, 600), "Crosshair");
        _wnd->setMouseCursorVisible(false);
        _player = new PlayerCrosshair();
        _enemigos = new Enemigo[5];
        enemigosEliminados = 0;
    }

    void Loop() {
        while (_wnd->isOpen()) {
            ProcesarEventos();
            Actualizar();
            Dibujar();
        }
    }

    void ProcesarEventos() {
        Event evt;
        while (_wnd->pollEvent(evt)) {
            switch (evt.type) {
            case Event::Closed:
                _wnd->close();
                break;
            case Event::MouseMoved:
                _player->Posicionar(evt.mouseMove.x, evt.mouseMove.y);
                break;
            case Event::MouseButtonPressed:
                if (evt.mouseButton.button == Mouse::Button::Left)
                    Disparar();
                break;
            }
        }
    }

    void Actualizar() {
        for (size_t i = 0; i < 5; i++) {
            _enemigos[i].Actualizar(_wnd);
        }
    }

    void Disparar() {
        Vector2f playerPos = _player->ObtenerPosicion();
        for (int i = 0; i < 5; i++) {
            if (_enemigos[i].EstaActivo()) {
                if (_enemigos[i].EstaEncima(playerPos.x, playerPos.y)) {
                    _enemigos[i].Matar();
                    enemigosEliminados++;
                }
            }
        }

        if (enemigosEliminados >= 5) {
            _wnd->close();
        }
    }

    void Dibujar() {
        _wnd->clear();
        for (int i = 0; i < 5; i++) {
            if (_enemigos[i].EstaActivo())
                _enemigos[i].Dibujar(_wnd);
        }
        _player->Dibujar(_wnd);
        _wnd->display();
    }

    ~Juego() {
        delete[] _enemigos;
        delete _player;
        delete _wnd;
    }
};
