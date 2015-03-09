
#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include <string>
#include "GameObject.h"
#include "GameObjectHero.h"
#include <cstdlib>

using namespace std;

class World
{
private:
	sf::RenderWindow *window;
	vector<GameObject> gameObjects;
	GameObjectHero hero;

public:
	World(sf::RenderWindow *window);

	int run();
};

#endif
