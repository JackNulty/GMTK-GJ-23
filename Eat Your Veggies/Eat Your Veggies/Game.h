#pragma once
#include "Veggie.h"
#include <SFML/Graphics.hpp> 

class Game {
public:
	Game();

	void run();
	void init();
	void render();
	void update(double dt);

	// main window
	sf::RenderWindow m_window;
	
private:
	
};
