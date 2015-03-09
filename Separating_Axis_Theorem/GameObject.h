
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

using namespace std;

class GameObject
{
protected:
	double x;
	double y;
public:
	sf::VertexArray vertices;

public:
	GameObject();
	GameObject(double x, double y, sf::VertexArray points);

public:
	void draw(sf::RenderWindow *window);
	double getX();
	double getY();
};

#endif
