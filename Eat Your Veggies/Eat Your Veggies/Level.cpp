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

	if (!MugTexture.loadFromFile("ASSETS/SPRITES/coffeeRounded.png"))
	{
		std::cout << "error loading coffee" << std::endl;
	}
	MugSprite.setTexture(MugTexture);
	MugSprite.setPosition(mugPos);
	MugSprite.setScale(4, 4);
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
	window.draw(floorSprite);
	window.draw(floorSprite1);
	window.draw(SaltSprite);
	window.draw(PepperSprite);
	window.draw(MugSprite);


}

void Level::handleObjects()
{
	saltPos.x -= 5;
	if (saltPos.x < -150 && saltPos.x > -160)
	{
		newObjectNeeded = true;
		saltPos.x = -170;
	}
	pepperPos.x -= 5;
	if (pepperPos.x < -150 && pepperPos.x > -160)
	{
		newObjectNeeded = true;
		pepperPos.x = -170;
	}
	mugPos.x -=5;
	if (mugPos.x < -150 && mugPos.x > -160)
	{
		newObjectNeeded = true;
		mugPos.x = -170;
	}


	if (newObjectNeeded == true)
	{
		newObjectNeeded = false;
		int respawnObject = (rand() % 3);
		if (respawnObject == 0)
		{
			if (saltPos.x < -150)
			{
				saltAvailable = true;
			}
			if (saltAvailable == true)
			{
				saltPos.x = 1300;
				saltAvailable = false;
			}
			else newObjectNeeded = true;
		}
		if (respawnObject == 1)
		{
			if (pepperPos.x < -150)
			{
				pepperAvailable = true;
			}
			if (pepperAvailable == true)
			{
				pepperPos.x = 1300;
				pepperAvailable = false;
			}
			else newObjectNeeded = true;
		}
		if (respawnObject == 2)
		{
			if (mugPos.x < -150)
			{
				mugAvailable = true;
			}
			if (mugAvailable == true)
			{
				mugPos.x = 1300;
				mugAvailable = false;
			}
			else newObjectNeeded = true;
		}
	}

	MugSprite.setPosition(mugPos);
	PepperSprite.setPosition(pepperPos);
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
