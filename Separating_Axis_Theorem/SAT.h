
#ifndef _SAT_H
#define _SAT_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class SAT
{
public:
	static sf::VertexArray getAxes(const sf::VertexArray &vertices);
	static double getDot(const sf::Vector2f &vector1, const sf::Vector2f &vector2);
	static double getLength(const sf::Vector2f &vector);
	static sf::Vector2f getProjection(const sf::VertexArray &vertices, const sf::Vector2f &axis);
	static bool isOverlap(const sf::Vector2f &vector1, const sf::Vector2f &vector2);
	static bool isPlaceFree(sf::VertexArray vertices, double x, double y, std::vector<GameObject> gameObjects);
};

#endif
