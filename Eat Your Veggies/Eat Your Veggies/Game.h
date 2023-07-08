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
	sf::RectangleShape rageBar;
	sf::RectangleShape levelBar;

	Veggie myVeg;
	Level myLevel;
	HUD myHud;
	Chef myChef;

	float rageMeter = 0;
	int rageBarSize = 0;

	float levelDistance = 0;
	int levelBarSize = 0;

	bool inCover = false;
	bool gameOver = false;
	
private:
	
};
