#include "particle.h"
#include "tweens.h"

void Particle::update(float dt)
{
	life += dt;
	center += velocity * dt;
	velocity += acceleration * dt;
}

bool Particle::isDead()
{
	return life > lifetime;
}

void Particle::draw(RenderWindow& window)
{
	float t = life / lifetime;

	RectangleShape shape;
	shape.setSize(Vector2f(100, 100));
	shape.setOrigin(50, 50);
	shape.setPosition(center);
	shape.setTexture(texture);

	ColorF color = lerp(startColor, endColor, t);
	shape.setFillColor(color);

	window.draw(shape);
}