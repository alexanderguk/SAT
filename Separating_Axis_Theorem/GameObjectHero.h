
#ifndef _GAMEOBJECTHERO_H
#define _GAMEOBJECTHERO_H

#include "GameObject.h"

class GameObjectHero : public GameObject
{
private:
	double targetX;
	double targetY;
	double speed;

public:
	GameObjectHero();
	GameObjectHero(double x, double y, const sf::VertexArray &points, double speed);
	void update(const std::vector<GameObject> &gameObjects);
	void draw(const std::shared_ptr<sf::RenderWindow> &window) const;
	void setTarget(int x, int y);
};

#endif
