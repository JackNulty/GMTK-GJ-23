#include "Level.h"

void Level::init()
{
	if (!floorTexture.loadFromFile("ASSETS/SPRITES/Counter.png"))
	{
		std::cout << "error" << std::endl;
	}
	floorSprite.setTexture(floorTexture);
	floorSprite.setPosition(floorPosX, floorPOsY);
	floorSprite.setScale(1, 1);

	floorSprite1.setTexture(floorTexture);
	floorSprite1.setPosition(floorPosX1, floorPOsY1);
	floorSprite1.setScale(1, 1);
}

void Level::update()
{
	floorPosX++;
	floorSprite.setPosition(floorPosX, floorPOsY);
	if (floorPosX >= SCREEN_WIDTH)
	{
		floorPosX = -1200;
	}
	std::cout << "1st platform pos" << floorPosX << std::endl;
	std::cout << "2nd platform pos" << floorPosX1 << std::endl;
	floorPosX1++;
	floorSprite1.setPosition(floorPosX1, floorPOsY1);
	if (floorPosX1 >= SCREEN_WIDTH)
	{
		floorPosX1 = -1200;
	}
}

void Level::render(sf::RenderWindow& window)
{
	window.draw(floorSprite);
	window.draw(floorSprite1);
}
