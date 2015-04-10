
#include <memory>
#include "Application.h"
#include "World.h"

int Application::run()
{
	// Create window
	auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(640, 480), "SFML Project");
	window->setFramerateLimit(FPS);

	// Load resourses

	// Run world
	World world(window);
	return world.run();
}
