
#include "Application.h"
#include "World.h"

int Application::run()
{
	// �������� ����
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(640, 480), "SFML Project");
	window.setFramerateLimit(FPS);

	// �������� ��������

	// ������ ����
	World world(&window);
	return world.run();
}
