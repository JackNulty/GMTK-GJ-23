#pragma once
#include "Globals.h"

class Level {
public:
	void init();
	void update();
	void render(sf::RenderWindow& window);

	sf::Sprite floorSprite;
	sf::Texture floorTexture;

private:

	int floorPosX = 0;
	int floorPOsY = 650;

};
