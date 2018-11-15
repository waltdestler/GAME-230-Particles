#include "particle.h"

void Particle::update(float dt)
{
	life -= dt;
	center += velocity * dt;
	velocity += acceleration * dt;
}

bool Particle::isDead()
{
	return life <= 0;
}

void Particle::draw(RenderWindow& window)
{
	RectangleShape shape;
	shape.setSize(Vector2f(100, 100));
	shape.setOrigin(50, 50);
	shape.setPosition(center);
	shape.setFillColor(Color::White);
	shape.setTexture(texture);
	window.draw(shape);
}