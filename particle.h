#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "colorf.h"

using namespace sf;

class Particle
{
public:

	float life = 0;
	float lifetime = 1;
	Vector2f center;
	Vector2f velocity;
	Vector2f acceleration;
	Texture* texture = nullptr;
	ColorF startColor = ColorF(1, 1, 1, 1);
	ColorF endColor = ColorF(1, 1, 1, 1);
	Vector2f startSize = Vector2f(50, 50);
	Vector2f endSize = Vector2f(50, 50);
	float startRot = 0;
	float endRot = 0;

	void update(float dt);
	bool isDead();
	void draw(RenderWindow& window);
};