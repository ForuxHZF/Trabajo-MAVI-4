#pragma once
#include "stdafx.h"
using namespace sf;

class PlayerCrosshair {
	Texture _crossTex;
	Sprite _crossSprite;

public:
	PlayerCrosshair() {
		_crossTex.loadFromFile("crosshair.png");
		_crossSprite.setTexture(_crossTex);
		_crossSprite.setScale(0.2, 0.2);
		Vector2u size = _crossTex.getSize();
		_crossSprite.setOrigin(size.x / 2.0f, size.y / 2.0f);
	}

	void Dibujar(RenderWindow* wnd) {
		wnd->draw(_crossSprite);
	}
	void Posicionar(float x, float y) {
		_crossSprite.setPosition(x, y);
	}
	Vector2f ObtenerPosicion() {
		return _crossSprite.getPosition();
	}
};

	
