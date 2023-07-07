#pragma once
#include "Veggie.h"
#include "Level.h"
#include "Globals.h"
#include "HUD.h"
#include "Chef.h"

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
	Chef myChef;
	
private:
	
};
