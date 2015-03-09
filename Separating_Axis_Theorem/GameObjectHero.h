
#ifndef GAMEOBJECTHERO_H
#define GAMEOBJECTHERO_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "SAT.h"

using namespace std;

typedef unsigned int uInt;

class GameObjectHero : GameObject
{
private:
	double targetX;
	double targetY;
	double speed;

public:
	GameObjectHero();
	GameObjectHero(double x, double y, sf::VertexArray points, double speed);
	void update(vector<GameObject> gameObjects, sf::RenderWindow *window);
	void draw(sf::RenderWindow *window);
	void setTarget(int x, int y);
};

#endif
