
#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <memory>
#include <SFML/Graphics.hpp>

class GameObject
{
protected:
	double x;
	double y;
	sf::VertexArray vertices;

public:
	GameObject();
	GameObject(double x, double y, const sf::VertexArray &points);

public:
	void draw(const std::shared_ptr<sf::RenderWindow> &window) const;
	double getX() const;
	double getY() const;
	const sf::VertexArray& getVertices() const;
};

#endif
