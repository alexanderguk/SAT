
#include <iostream>
#include "World.h"
#include "SAT.h"
#include "GameObject.h"

World::World(const std::shared_ptr<sf::RenderWindow> &window)
{
	this->window = window;
}

int World::run()
{
	// Initialization of all game objects
	init();

	// Simulation start
	sf::Event ev;
	while (window->isOpen())
	{
		// Handle events
		while (window->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window->close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
			hero.setTarget(localPosition.x, localPosition.y);
		}

		// Movement
		hero.update(gameObjects);

		// Draw
		window->clear();

		for (GameObject gameObject : gameObjects)
		{
			gameObject.draw(window);
		}
		hero.draw(window);

		window->display();
	}

	return 0;
}

void World::init()
{
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < 10; ++i)
	{
		sf::VertexArray vertices;
		vertices.append(sf::Vertex(sf::Vector2f(0.f + rand() % 50, 0.f + rand() % 50)));
		vertices.append(sf::Vertex(sf::Vector2f(70.f + rand() % 50, 20.f + rand() % 50)));
		vertices.append(sf::Vertex(sf::Vector2f(40.f + rand() % 50, 50.f + rand() % 50)));
		int obstacleX = rand() % (window->getSize().x - 50);
		int obstacleY = rand() % (window->getSize().y - 50);
		while (!SAT::isPlaceFree(vertices, obstacleX, obstacleY, gameObjects))
		{
			obstacleX = rand() % (window->getSize().x - 50);
			obstacleY = rand() % (window->getSize().y - 50);
		}
		gameObjects.push_back(GameObject(obstacleX, obstacleY, vertices));
	}

	sf::VertexArray vertices;
	vertices.append(sf::Vertex(sf::Vector2f(-30, -30)));
	vertices.append(sf::Vertex(sf::Vector2f(0, 40)));
	vertices.append(sf::Vertex(sf::Vector2f(30, -30)));
	int heroX = rand() % (window->getSize().x - 50);
	int heroY = rand() % (window->getSize().y - 50);
	while (!SAT::isPlaceFree(vertices, heroX, heroY, gameObjects))
	{
		heroX = rand() % (window->getSize().x - 50);
		heroY = rand() % (window->getSize().y - 50);
	}
	hero = GameObjectHero(heroX, heroY, vertices, 3);
}
