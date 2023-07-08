#pragma once
#include "Globals.h"

class Level {
public:
	void init();
	void update();
	void render(sf::RenderWindow& window);
	void handleObjects();
	bool handleCollisons(sf::Sprite playerSprite);

	void increaseSpeed(int newSpeed);

private:
	int gameSpeed = minSpeed;

	bool spawnAvailable(sf::Sprite vegToCheck);

	bool newObjectNeeded = true;

	sf::Sprite floorSprite;
	sf::Texture floorTexture;

	sf::Sprite floorSprite1;

	sf::Sprite floorHiddenSprite;
	sf::Texture floorHiddenTexture;

	sf::Sprite SaltSprite;
	sf::Texture SaltTexture;
	bool saltAvailable = true;

	sf::Sprite PepperSprite;
	sf::Texture PepperTexture;
	bool pepperAvailable = true;

	sf::Sprite MugSprite;
	sf::Texture MugTexture;
	bool mugAvailable = true;

	sf::Sprite BowlSprite;
	sf::Texture BowlTexture;
	bool bowlAvailable = false;

	sf::Sprite RackSprite;
	sf::Texture RackTexture;
	bool rackAvailable = true;

	sf::Vector2f saltPos = sf::Vector2f(-500, 335);
	sf::Vector2f pepperPos = sf::Vector2f(-500, 335);
	sf::Vector2f mugPos = sf::Vector2f(-500, 345);
	sf::Vector2f bowlPos = sf::Vector2f(600, 333);
	sf::Vector2f rackPos = sf::Vector2f(-500, 260);

	float tempXPos = 0;

	int floorPosX = 0;
	int floorPOsY = 575;

	int floorPosX1 = 1280;
	int floorPOsY1 = 575;

	int floorSize = 1280;
};
