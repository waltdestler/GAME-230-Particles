#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>

using namespace sf;

class Particle
{
public:

	float life;
	Vector2f center;
	Vector2f velocity;
	Vector2f acceleration;
	Texture* texture;

	void update(float dt);
	bool isDead();
	void draw(RenderWindow& window);
};