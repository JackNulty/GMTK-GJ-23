#include "Level.h"

void Level::init()
{
	if (!floorTexture.loadFromFile("ASSETS/SPRITES/Faceset.png"))
	{
		std::cout << "error" << std::endl;
	}
	floorSprite.setTexture(floorTexture);
	floorSprite.setPosition(floorPosX, floorPOsY);
	floorSprite.setScale(1, 1);
}

void Level::update()
{
	floorPosX++;
	floorSprite.setPosition(floorPosX, floorPOsY);
	if (floorPosX >= SCREEN_WIDTH)
	{
		floorPosX = 0;
	}
}

void Level::render(sf::RenderWindow& window)
{
	window.draw(floorSprite);
}
