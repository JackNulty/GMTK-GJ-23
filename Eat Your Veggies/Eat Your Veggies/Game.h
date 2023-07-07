#pragma once
#include "Veggie.h"
#include "Level.h"
#include "Globals.h"
#include "HUD.h"

class Game {
public:
	Game();

	void run();
	void init();
	void render();
	void update();
	void collision();

	// main window
	sf::RenderWindow m_window;

	Veggie myVeg;
	Level myLevel;
	HUD myHud;
	
private:
	
};
