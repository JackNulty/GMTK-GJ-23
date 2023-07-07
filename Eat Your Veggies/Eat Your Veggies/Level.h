#pragma once
#include "Globals.h"

class Level {
public:
	void init();
	void update();
	void render(sf::RenderWindow& window);

	sf::Sprite floorSprite;
	sf::Texture floorTexture;

	sf::Sprite floorSprite1;

private:

	int floorPosX = 0;
	int floorPOsY = 650;

	int floorPosX1 = 1200;
	int floorPOsY1 = 650;

};
