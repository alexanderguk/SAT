
#ifndef SAT_H
#define SAT_H

#include <SFML/Graphics.hpp>
#include "GameObjectHero.h"
#include "GameObject.h"

class SAT
{
public:
	static sf::VertexArray getAxes(sf::VertexArray vertices);
	static double getDot(sf::Vector2f vector1, sf::Vector2f vector2);
	static sf::Vector2f getProjection(sf::VertexArray vertices, sf::Vector2f axis);
	static bool isOverlap(sf::Vector2f vector1, sf::Vector2f vector2);
	static double getLength(sf::Vector2f vector);
	static bool isPlaceFree(sf::VertexArray vertices, double x, double y, vector<GameObject> gameObjects, sf::RenderWindow *window);
};

#endif
