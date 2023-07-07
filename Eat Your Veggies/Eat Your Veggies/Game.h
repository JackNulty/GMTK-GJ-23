#pragma once
#include "Veggie.h"
#include "Level.h"
#include "Globals.h"

class Game {
public:
	Game();

	void run();
	void init();
	void render();
	void update();

	// main window
	sf::RenderWindow m_window;

	Veggie myVeg;
	Level myLevel;
	
private:
	
};
