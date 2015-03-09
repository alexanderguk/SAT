
#include "GameObject.h"

GameObject::GameObject()
{
	sf::VertexArray emptyVector;
	GameObject(0.0f, 0.0f, emptyVector);
}

GameObject::GameObject(double x, double y, sf::VertexArray points)
{
	this->x = x;
	this->y = y;
	vertices = points;
}

void GameObject::draw(sf::RenderWindow *window)
{
	sf::VertexArray triangle(sf::TrianglesFan);
	for (int i = 0; i < vertices.getVertexCount(); ++i)
		triangle.append(sf::Vertex(sf::Vector2f(vertices[i].position.x + x, vertices[i].position.y + y)));
	triangle[0].color = sf::Color::Green;
	triangle[1].color = sf::Color::Green;
	triangle[2].color = sf::Color::Green;
	window->draw(triangle);
}

double GameObject::getX()
{
	return x;
}

double GameObject::getY()
{
	return y;
}
