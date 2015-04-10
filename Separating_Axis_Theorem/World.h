
#ifndef _WORLD_H
#define _WORLD_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "GameObjectHero.h"

class World
{
private:
	std::shared_ptr<sf::RenderWindow> window;
	std::vector<GameObject> gameObjects;
	GameObjectHero hero;

public:
	World(const std::shared_ptr<sf::RenderWindow> &window);

	int run();

private:
	void init();
};

#endif
