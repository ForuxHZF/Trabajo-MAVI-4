#pragma once
#include "stdafx.h"

using namespace sf;

class Enemigo {

    Texture _enemyTex;
    Sprite _enemySprite;
    bool _estaVivo;
    bool _estarVisible;
    Clock _clock;
    float _tiempoVisible;
    float _tiempoApagado;

    Vector2f _randomPos(Vector2u maxPos) {
        Vector2f random((float)(rand() % maxPos.x), (float)(rand() % maxPos.y));
        return random;
    }

public:
    Enemigo() {
        _enemyTex.loadFromFile("et.png");
        _enemySprite.setTexture(_enemyTex);
        _estaVivo = true;
        _enemySprite.setScale(0.04f, 0.04f);
        _estarVisible = false;
        _tiempoVisible = 0.5f;
        _tiempoApagado = 1.0f; // Añadir un tiempo de apagado

    }

    bool EstaVivo() {
        return _estaVivo;
    }

    bool EstaEncima(float x, float y) {
        FloatRect bounds = _enemySprite.getGlobalBounds();
        return bounds.contains(x, y);
    }

    void Matar() {
        _estaVivo = false;
    }

    void Dibujar(RenderWindow* wnd) {
        wnd->draw(_enemySprite);
    }

    bool EstaActivo() {
        return _estaVivo && _estarVisible;
    }

    void Actualizar(RenderWindow* wnd) {
        if (!_estaVivo)
            return;

        if (!_estarVisible) {
            if (_clock.getElapsedTime().asSeconds() > _tiempoApagado) {
                _clock.restart();
                if (rand() % 100 < 25) {
                    _estarVisible = true;
                    _enemySprite.setPosition(_randomPos(wnd->getSize()));
                }
            }
        }
        else {
            if (_clock.getElapsedTime().asSeconds() > _tiempoVisible)
                _estarVisible = false;
            _clock.restart();
        }
    }
};