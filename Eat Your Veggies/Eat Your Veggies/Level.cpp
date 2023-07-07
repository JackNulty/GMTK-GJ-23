#include "Level.h"

void Level::init()
{
	if (!floorTexture.loadFromFile("ASSETS/SPRITES/Counter.png"))
	{
		std::cout << "error" << std::endl;
	}
	floorSprite.setTexture(floorTexture);
	floorSprite.setPosition(floorPosX, floorPOsY);
	floorSprite.setScale(8, 8);

	floorSprite1.setTexture(floorTexture);
	floorSprite1.setPosition(floorPosX1, floorPOsY1);
	floorSprite1.setScale(8, 8);

	if (!SaltTexture.loadFromFile("ASSETS/SPRITES/salt.png"))
	{
		std::cout << "error" << std::endl;
	}
	SaltSprite.setTexture(SaltTexture);
	SaltSprite.setPosition(100,320);
	SaltSprite.setScale(4, 4);
}

void Level::update()
{
	floorPosX--;
	floorSprite.setPosition(floorPosX, floorPOsY);
	if (floorPosX <= -floorSize)
	{
		floorPosX = floorSize;
	}
	std::cout << "1st platform pos" << floorPosX << std::endl;
	std::cout << "2nd platform pos" << floorPosX1 << std::endl;
	floorPosX1--;
	floorSprite1.setPosition(floorPosX1, floorPOsY1);
	if (floorPosX1 <= -floorSize)
	{
		floorPosX1 = floorSize;
	}
}

void Level::render(sf::RenderWindow& window)
{
	window.draw(SaltSprite);
	window.draw(floorSprite);
	window.draw(floorSprite1);
}
