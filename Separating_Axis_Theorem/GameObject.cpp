
#include "GameObject.h"

GameObject::GameObject() : x(0), y(0)
{
}

GameObject::GameObject(double x, double y, const sf::VertexArray &points)
{
	this->x = x;
	this->y = y;
	vertices = points;
}

void GameObject::draw(const std::shared_ptr<sf::RenderWindow> &window) const
{
	sf::VertexArray triangle(sf::TrianglesFan);
	for (unsigned int i = 0; i < vertices.getVertexCount(); ++i)
		triangle.append(sf::Vertex(sf::Vector2f(vertices[i].position.x + static_cast<float>(x), vertices[i].position.y + static_cast<float>(y))));
	triangle[0].color = sf::Color::Green;
	triangle[1].color = sf::Color::Green;
	triangle[2].color = sf::Color::Green;
	window->draw(triangle);
}

double GameObject::getX() const
{
	return x;
}

double GameObject::getY() const
{
	return y;
}

const sf::VertexArray& GameObject::getVertices() const
{
	return vertices;
}
