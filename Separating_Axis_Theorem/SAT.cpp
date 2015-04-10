
#include "SAT.h"

sf::VertexArray SAT::getAxes(const sf::VertexArray &vertices)
{
	sf::VertexArray axes;
	for (unsigned int i = 0; i < vertices.getVertexCount(); ++i)
	{
		sf::Vector2f p1 = vertices[i].position;
		sf::Vector2f p2 = vertices[i + 1 == vertices.getVertexCount() ? 0 : i + 1].position;
		//sf::Vector2f edge = p1 - p2;
		sf::Vector2f edge = sf::Vector2f(p1.x - p2.x, p1.y - p2.y);
		sf::Vector2f normal = sf::Vector2f(edge.y, -edge.x);
		axes.append(normal);
	}
	return axes;
}

double SAT::getDot(const sf::Vector2f &vector1, const sf::Vector2f &vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y;
}

double SAT::getLength(const sf::Vector2f &vector)
{
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2));
}

sf::Vector2f SAT::getProjection(const sf::VertexArray &vertices, const sf::Vector2f &axis)
{
	double min = getDot(axis, vertices[0].position);
	double max = min;
	for (unsigned int i = 1; i < vertices.getVertexCount(); ++i)
	{
		double p = getDot(axis, vertices[i].position);
		if (p < min)
			min = p;
		else if (p > max)
			max = p;
	}
	sf::Vector2f projection(static_cast<float>(min), static_cast<float>(max));
	//double length = getLength(projection);
	//projection = sf::Vector2f(min / length, max / length);
	return projection;
}

bool SAT::isOverlap(const sf::Vector2f &vector1, const sf::Vector2f &vector2)
{
	return (vector1.x < vector2.x && vector2.x < vector1.y) || (vector1.x < vector2.y && vector2.y < vector1.y) \
		|| (vector2.x < vector1.x && vector1.x < vector2.y) || (vector2.x < vector1.y && vector1.y < vector2.y);
}

bool SAT::isPlaceFree(sf::VertexArray vertices, double x, double y, std::vector<GameObject> gameObjects)
{
	sf::VertexArray heroVertices = vertices;
	for (unsigned int i = 0; i < heroVertices.getVertexCount(); ++i)
	{
		heroVertices[i].position.x += static_cast<float>(x);
		heroVertices[i].position.y += static_cast<float>(y);
	}

	std::vector<sf::VertexArray> gameObjectsVertices;
	for (unsigned int i = 0; i < gameObjects.size(); ++i)
	{
		gameObjectsVertices.push_back(gameObjects[i].getVertices());
		for (unsigned int j = 0; j < gameObjectsVertices[i].getVertexCount(); ++j)
		{
			gameObjectsVertices[i][j].position.x += static_cast<float>(gameObjects[i].getX());
			gameObjectsVertices[i][j].position.y += static_cast<float>(gameObjects[i].getY());
		}
	}

	sf::VertexArray axes1 = getAxes(heroVertices);
	for (sf::VertexArray gameObjectVertices : gameObjectsVertices)
	{
		sf::VertexArray axes2 = getAxes(gameObjectVertices);
		bool noCollision = false;

		for (unsigned int i = 0; i < axes1.getVertexCount(); ++i)
		{
			sf::Vector2f axis = axes1[i].position;
			sf::Vector2f projection1 = getProjection(heroVertices, axis);
			sf::Vector2f projection2 = getProjection(gameObjectVertices, axis);
			if (!isOverlap(projection1, projection2))
			{
				noCollision = true;
				break;
			}
		}
		if (!noCollision)
		{
			for (unsigned int i = 0; i < axes2.getVertexCount(); ++i)
			{
				sf::Vector2f axis = axes2[i].position;
				sf::Vector2f projection1 = getProjection(heroVertices, axis);
				sf::Vector2f projection2 = getProjection(gameObjectVertices, axis);
				if (!isOverlap(projection1, projection2))
				{
					noCollision = true;
					break;
				}
			}
			if (!noCollision)
				return false;
		}
	}
	return true;
}
