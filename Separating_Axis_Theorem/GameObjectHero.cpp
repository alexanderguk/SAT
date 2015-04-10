
#include "GameObjectHero.h"
#include "SAT.h"

GameObjectHero::GameObjectHero() : GameObject(), targetX(x), targetY(y), speed(0)
{
}

GameObjectHero::GameObjectHero(double x, double y, const sf::VertexArray &points, double speed) :
GameObject(x, y, points), targetX(x), targetY(y), speed(speed)
{
}

void GameObjectHero::update(const std::vector<GameObject> &gameObjects)
{
	double distance;
	distance = sqrt(pow(targetX - x, 2) + pow(targetY - y, 2));
	double possibleX, possibleY;
	possibleX = x + speed * ((targetX - x) / distance);
	possibleY = y + speed * ((targetY - y) / distance);
	if (distance > 2)
	{
		if (SAT::isPlaceFree(vertices, possibleX, possibleY, gameObjects))
		{
			x += speed * ((targetX - x) / distance);
			y += speed * ((targetY - y) / distance);
		}
	}
	else if (SAT::isPlaceFree(vertices, possibleX, possibleY, gameObjects))
	{
		x = targetX;
		y = targetY;
	}
}

void GameObjectHero::draw(const std::shared_ptr<sf::RenderWindow> &window) const
{
	sf::VertexArray triangle(sf::Triangles);
	for (unsigned int i = 0; i < vertices.getVertexCount(); ++i)
		triangle.append(sf::Vertex(sf::Vector2f(vertices[i].position.x + static_cast<float>(x), vertices[i].position.y + static_cast<float>(y))));
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Red;
	triangle[2].color = sf::Color::Red;
	window->draw(triangle);
}

void GameObjectHero::setTarget(int x, int y)
{
	targetX = x;
	targetY = y;
}
