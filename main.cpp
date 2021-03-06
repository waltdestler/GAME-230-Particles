#include <cmath>
#include <string>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "particle.h"

using namespace std;
using namespace sf;

void update_state(float dt);
void render_frame();
void create_particle();

RenderWindow window;
//Texture particleTex;

vector<unique_ptr<Particle>> particles;

const float PARTICLES_PER_SECOND = 1;
float accumulatedParticles = 0;

int main()
{
	window.create(VideoMode(1024, 768), "SFML Example");
	//particleTex.loadFromFile("particle.png");

	Clock clock;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			} 
		}

		float dt = clock.restart().asSeconds();

		update_state(dt);
		render_frame();
		window.display();
	}

	return 0;
}

void update_state(float dt)
{
	// Update existing particles.
	for (int i = particles.size() - 1; i >= 0; --i)
	{
		particles[i]->update(dt);
		if (particles[i]->isDead())
		{
			particles.erase(particles.begin() + i);
		}
	}

	// Spawn new particles.
	accumulatedParticles += PARTICLES_PER_SECOND * dt;
	while (accumulatedParticles >= 1)
	{
		create_particle();
		accumulatedParticles -= 1;
	}
}

void render_frame()
{
	window.clear();

	for (int i = 0; i < particles.size(); ++i)
	{
		particles[i]->draw(window);
	}
}

void create_particle()
{
	Particle* p = new Particle();

	p->lifetime = 0.75f;

	Vector2i mousePos = Mouse::getPosition(window);
	p->center = Vector2f((float)mousePos.x, (float)mousePos.y);

	//p->texture = &particleTex;

	//p->velocity.x = (float)(rand() % 250 - 125);
	//p->velocity.y = (float)(rand() % 250 - 125);

	//p->acceleration.y = -750;

	//p->startColor = ColorF(1, 0, 0, 1);
	//p->endColor = ColorF(1, 1, 0, 0);

	//p->startSize = Vector2f(50, 50);
	//p->endSize = Vector2f(200, 200);

	//p->startRot = rand() % 720 - 360;
	//p->endRot = rand() % 720 - 360;

	particles.push_back(unique_ptr<Particle>(p));
}