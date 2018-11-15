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
	shape.setPosition(center);
	shape.setTexture(texture);

	Vector2f size = lerp(startSize, endSize, t);
	shape.setSize(size);
	shape.setOrigin(size / 2.0f);

	ColorF color = lerp(startColor, endColor, t);
	shape.setFillColor(color);

	window.draw(shape);
}