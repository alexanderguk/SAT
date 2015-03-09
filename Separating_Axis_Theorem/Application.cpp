
#include "Application.h"
#include "World.h"

int Application::run()
{
	// Создание окна
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(640, 480), "SFML Project");
	window.setFramerateLimit(FPS);

	// Загрузка ресурсов

	// Запуск мира
	World world(&window);
	return world.run();
}
