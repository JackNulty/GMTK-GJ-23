#pragma once
#include "Globals.h"

class Level {
public:
	void init();
	void update();
	void render(sf::RenderWindow& window);

private:
	sf::RectangleShape floor;

	sf::Sprite floorSprite;
	sf::Texture floorTexture;


};
