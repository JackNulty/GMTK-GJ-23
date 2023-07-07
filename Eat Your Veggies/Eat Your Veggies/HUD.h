#pragma once
#include "Globals.h"
class HUD
{
public:
	void init();
	void render(sf::RenderWindow& window);
private:
	// Setting up HUD
	sf::Sprite rageBar;
	sf::Sprite progressBar;
	sf::Texture barsTexture;

};