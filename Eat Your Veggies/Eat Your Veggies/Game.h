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
	sf::Sprite gameWinSprite;
	sf::Texture gameWinTexture;
	sf::RectangleShape rageBar;
	sf::RectangleShape levelBar;

	Veggie myVeg;
	Level myLevel;
	HUD myHud;
	Chef myChef;

	float rageMeter = 0;
	int rageBarSize = 0;

	int levelPopupCounter = 240;

	float levelDistance = 0;
	int levelBarSize = 0;

	bool inCover = false;
	bool gameOver = false;
	bool gameWin = false;
	
private:
	int gameSpeed = minSpeed;
	void increaseGameSpeed();
	int levelNo = 0;

	sf::Sprite levelCompleteSprite;
	sf::Texture levelCompleteTex;
	bool levelCompleted;
	
};
