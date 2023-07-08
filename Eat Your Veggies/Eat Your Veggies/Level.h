#pragma once
#include "Globals.h"

class Level {
public:
	void init();
	void update();
	void render(sf::RenderWindow& window);
	void handleObjects();
	bool handleCollisons(sf::Sprite playerSprite);

private:
	bool newObjectNeeded = true;

	sf::Sprite floorSprite;
	sf::Texture floorTexture;

	sf::Sprite floorSprite1;

	sf::Sprite SaltSprite;
	sf::Texture SaltTexture;
	bool saltAvailable = true;

	sf::Sprite PepperSprite;
	sf::Texture PepperTexture;
	bool pepperAvailable = true;

	sf::Vector2f saltPos = sf::Vector2f(-500, 335);
	sf::Vector2f pepperPos = sf::Vector2f(-500, 335);

	int floorPosX = 0;
	int floorPOsY = 575;

	int floorPosX1 = 1280;
	int floorPOsY1 = 575;

	int floorSize = 1280;
};
