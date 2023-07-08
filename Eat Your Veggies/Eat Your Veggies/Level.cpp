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

	if (!BowlTexture.loadFromFile("ASSETS/SPRITES/fruitBowl.png"))
	{
		std::cout << "error loading fruit bowl" << std::endl;
	}
	BowlSprite.setTexture(BowlTexture);
	BowlSprite.setPosition(bowlPos);
	BowlSprite.setScale(4, 4);

	if (!RackTexture.loadFromFile("ASSETS/SPRITES/spiceRack.png"))
	{
		std::cout << "error loading spice rack" << std::endl;
	}
	RackSprite.setTexture(RackTexture);
	RackSprite.setPosition(rackPos);
	RackSprite.setScale(5, 5);
}

void Level::update()
{
	floorPosX-= gameSpeed;
	handleObjects();
	if (floorPosX <= -floorSize)
	{
		floorPosX = floorSize;
	}
	//std::cout << "1st platform pos" << floorPosX << std::endl;
	//std::cout << "2nd platform pos" << floorPosX1 << std::endl;
	floorPosX1-= gameSpeed;
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
	window.draw(BowlSprite);
	window.draw(RackSprite);

}

void Level::handleObjects()
{
	saltPos.x -=gameSpeed;
	if (saltPos.x < -150 && saltPos.x > -160)
	{
		newObjectNeeded = true;
		saltPos.x = -170;
	}
	pepperPos.x -= gameSpeed;
	if (pepperPos.x < -150 && pepperPos.x > -160)
	{
		newObjectNeeded = true;
		pepperPos.x = -170;
	}
	mugPos.x -= gameSpeed;
	if (mugPos.x < -250 && mugPos.x > -260)
	{
		newObjectNeeded = true;
		mugPos.x = -270;
	}
	bowlPos.x-= gameSpeed;
	if (bowlPos.x < -350 && bowlPos.x > -360)
	{
		newObjectNeeded = true;
		bowlPos.x = -370;
	}
	rackPos.x -= gameSpeed;
	if (rackPos.x < -450 && rackPos.x > -460)
	{
		newObjectNeeded = true;
		rackPos.x = -470;
	}




	if (newObjectNeeded == true)
	{
		newObjectNeeded = false;
		int respawnObject = (rand() % 5);
		if (respawnObject == 0)
		{
			if (saltPos.x < -150)
			{
				saltAvailable = true;
			}
			if (saltAvailable == true)
			{
				tempXPos = (rand() % 400) + 1300;
				saltPos.x = tempXPos;
				SaltSprite.setPosition(saltPos);
				if(spawnAvailable(SaltSprite) == true)
				{
					saltPos.x += 350;
				}
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
				tempXPos = (rand() % 400) + 1300;
				pepperPos.x = tempXPos;
				PepperSprite.setPosition(pepperPos);
				if (spawnAvailable(PepperSprite) == true)
				{
					pepperPos.x += 350;
				}
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
				tempXPos = (rand() % 400) + 1300;
				mugPos.x = tempXPos;
				MugSprite.setPosition(mugPos);
				if (spawnAvailable(MugSprite) == true)
				{
					mugPos.x += 350;
				}
				mugAvailable = false;
			}
			else newObjectNeeded = true;
		}
		if (respawnObject == 3)
		{
			if (bowlPos.x < -150)
			{
				bowlAvailable = true;
			}
			if (bowlAvailable == true)
			{
				tempXPos = (rand() % 400) + 1300;
				bowlPos.x = tempXPos;
				BowlSprite.setPosition(bowlPos);
				if (spawnAvailable(BowlSprite) == true)
				{
					bowlPos.x += 350;
				}
				bowlAvailable = false;
			}
			else newObjectNeeded = true;
		}

		if (respawnObject == 4)
		{
			if (rackPos.x < -150)
			{
				rackAvailable = true;
			}
			if (rackAvailable == true)
			{
				tempXPos = (rand() % 400) + 1300;
				rackPos.x = tempXPos;
				RackSprite.setPosition(rackPos);
				if (spawnAvailable(RackSprite) == true)
				{
					rackPos.x += 350;
				}
				rackAvailable = false;
			}
			else newObjectNeeded = true;
		}
	}

	MugSprite.setPosition(mugPos);
	PepperSprite.setPosition(pepperPos);
	SaltSprite.setPosition(saltPos);
	BowlSprite.setPosition(bowlPos);
	RackSprite.setPosition(rackPos);
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
	if (playerSprite.getGlobalBounds().intersects(MugSprite.getGlobalBounds()))
	{
		return true;
	}
	if (playerSprite.getGlobalBounds().intersects(BowlSprite.getGlobalBounds()))
	{
		return true;
	}
	if (playerSprite.getGlobalBounds().intersects(RackSprite.getGlobalBounds()))
	{
		return true;
	}
	return false;
}

bool Level::spawnAvailable(sf::Sprite vegToCheck)
{
	if (saltAvailable == false)
	{
		if (vegToCheck.getGlobalBounds().intersects(SaltSprite.getGlobalBounds()))
		{
			return true;
		}
	}
	if (pepperAvailable == false)
	{
		if (vegToCheck.getGlobalBounds().intersects(PepperSprite.getGlobalBounds()))
		{
			return true;
		}
	}
	if (mugAvailable == false)
	{
		if (vegToCheck.getGlobalBounds().intersects(MugSprite.getGlobalBounds()))
		{
			return true;
		}
	}
	if (bowlAvailable == false)
	{
		if (vegToCheck.getGlobalBounds().intersects(BowlSprite.getGlobalBounds()))
		{
			return true;
		}
	}
	if (rackAvailable == false)
	{
		if (vegToCheck.getGlobalBounds().intersects(RackSprite.getGlobalBounds()))
		{
			return true;
		}
	}

	return false;
}
