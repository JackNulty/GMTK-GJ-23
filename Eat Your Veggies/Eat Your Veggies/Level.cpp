#include "Level.h"

void Level::init()
{
	if (!floorTexture.loadFromFile("ASSETS/SPRITES/Faceset.png"))
	{
		std::cout << "error" << std::endl;
	}
	floorSprite.setTexture(floorTexture);
	floorSprite.setPosition(0, 670);
	floorSprite.setScale(1, 1);
}

void Level::update()
{
}

void Level::render(sf::RenderWindow& window)
{
	window.draw(floorSprite);
}
