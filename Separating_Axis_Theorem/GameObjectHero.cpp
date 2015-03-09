
#include "GameObjectHero.h"

void GameObjectHero::draw(sf::RenderWindow *window)
{
	sf::VertexArray triangle(sf::Triangles);
	for (int i = 0; i < vertices.getVertexCount(); ++i)
		triangle.append(sf::Vertex(sf::Vector2f(vertices[i].position.x + x, vertices[i].position.y + y)));
	triangle[0].color = sf::Color::Red;
	triangle[1].color = sf::Color::Red;
	triangle[2].color = sf::Color::Red;
	window->draw(triangle);
}

GameObjectHero::GameObjectHero() :
GameObject()
{

}

GameObjectHero::GameObjectHero(double x, double y, sf::VertexArray points, double speed) :
GameObject(x, y, points)
{
	this->speed = speed;
	this->targetX = x;
	this->targetY = y;
}

void GameObjectHero::update(vector<GameObject> gameObjects, sf::RenderWindow *window)
{
	double distance;
	distance = sqrt(pow(targetX - x, 2) + pow(targetY - y, 2));
	double possibleX, possibleY;
	possibleX = x + speed * ((targetX - x) / distance);
	possibleY = y + speed * ((targetY - y) / distance);
	if (distance > 2)
	{
		if (SAT::isPlaceFree(vertices, possibleX, possibleY, gameObjects, window))
		{
			x += speed * ((targetX - x) / distance);
			y += speed * ((targetY - y) / distance);
		}
	}
	else if (SAT::isPlaceFree(vertices, possibleX, possibleY, gameObjects, window))
	{
		x = targetX;
		y = targetY;
	}
}

void GameObjectHero::setTarget(int x, int y)
{
	targetX = x;
	targetY = y;
}
