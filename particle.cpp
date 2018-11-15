#include "particle.h"
#include "tweens.h"

void Particle::update(float dt)
{
	life += dt;
	//center += velocity * dt;
	//velocity += acceleration * dt;
}

bool Particle::isDead()
{
	return life > lifetime;
}

void Particle::draw(RenderWindow& window)
{
	RectangleShape shape;
	shape.setPosition(center);
	shape.setSize(Vector2f(50, 50));
	shape.setOrigin(25, 25);
	
	//shape.setTexture(texture);

	//float t = life / lifetime;
	//Vector2f size = lerp(startSize, endSize, t);
	//shape.setSize(size);
	//shape.setOrigin(size / 2.0f);

	//ColorF color = lerp(startColor, endColor, t);
	//shape.setFillColor(color);

	//float rot = lerp(startRot, endRot, t);
	//shape.setRotation(rot);

	window.draw(shape);
}