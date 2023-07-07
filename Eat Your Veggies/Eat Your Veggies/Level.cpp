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
	SaltSprite.setPosition(saltPos);
	SaltSprite.setScale(4, 4);

	if (!PepperTexture.loadFromFile("ASSETS/SPRITES/pepper.png"))
	{
		std::cout << "error loading pepper" << std::endl;
	}
	PepperSprite.setTexture(PepperTexture);
	PepperSprite.setPosition(pepperPos);
	PepperSprite.setScale(4, 4);
}

void Level::update()
{
	floorPosX--;
	handleObjects();
	if (floorPosX <= -floorSize)
	{
		floorPosX = floorSize;
	}
	//std::cout << "1st platform pos" << floorPosX << std::endl;
	//std::cout << "2nd platform pos" << floorPosX1 << std::endl;
	floorPosX1--;
	if (floorPosX1 <= -floorSize)
	{
		floorPosX1 = floorSize;
	}
	floorSprite.setPosition(floorPosX, floorPOsY);
	floorSprite1.setPosition(floorPosX1, floorPOsY1);
}

void Level::render(sf::RenderWindow& window)
{
	window.draw(SaltSprite);
	window.draw(PepperSprite);
	window.draw(floorSprite);
	window.draw(floorSprite1);
}

void Level::handleObjects()
{
	saltPos.x--;






	SaltSprite.setPosition(saltPos);
}

bool Level::handleCollisons(sf::Sprite playerSprite)
{
	if (playerSprite.getGlobalBounds().intersects(SaltSprite.getGlobalBounds()))
	{
		return true;
	}
	if (playerSprite.getGlobalBounds().intersects(PepperSprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}
