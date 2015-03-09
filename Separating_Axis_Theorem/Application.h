
#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

typedef unsigned int uInt;

class Application
{
private:
	const uInt FPS = 60;

public:
	int run();
};

#endif
