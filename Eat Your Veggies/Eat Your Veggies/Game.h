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

	sf::Sprite background;
	sf::Texture backgroundTexture;
	sf::Sprite gameOverSprite;
	sf::Texture gameOverTexture;

	Veggie myVeg;
	Level myLevel;
	HUD myHud;
	Chef myChef;

	int rageMeter = 0;
	bool inCover = false;
	bool gameOver = false;
	
private:
	
};
