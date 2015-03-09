
#include "World.h"

World::World(sf::RenderWindow *window)
{
	this->window = window;
}

int World::run()
{
	srand(time(0));
	// Инициализация всех объектов
	for (int i = 0; i < 10; ++i)
	{
		sf::VertexArray vertices;
		vertices.append(sf::Vertex(sf::Vector2f(0 + rand() % 50, 0 + rand() % 50)));
		vertices.append(sf::Vertex(sf::Vector2f(70 + rand() % 50, 20 + rand() % 50)));
		vertices.append(sf::Vertex(sf::Vector2f(40 + rand() % 50, 50 + rand() % 50)));
		vertices.append(sf::Vertex(sf::Vector2f(-10 + rand() % 50, 60 + rand() % 50)));
		gameObjects.push_back(GameObject(rand() % (window->getSize().x - 50), rand() % (window->getSize().y - 50), vertices));
	}
	sf::VertexArray vertices;
	vertices.append(sf::Vertex(sf::Vector2f(45, 0)));
	vertices.append(sf::Vertex(sf::Vector2f(30, 50)));
	vertices.append(sf::Vertex(sf::Vector2f(80, 50)));
	hero = GameObjectHero(rand() % (window->getSize().x - 50), rand() % (window->getSize().y - 50), vertices, 3);

	// Запуск симуляции
	sf::Event ev;
	while (window->isOpen())
	{
		// Обрабокта событий
		while (window->pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
				window->close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
			hero.setTarget(localPosition.x, localPosition.y);
		}

		// Передвижение

		// Рисование
		window->clear();

		for (GameObject gameObject : gameObjects)
		{
			gameObject.draw(window);
		}
		hero.draw(window);
		hero.update(gameObjects, window);

		window->display();
	}

	return 0;
}
