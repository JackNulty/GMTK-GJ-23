#pragma once
#include "Globals.h"

class Veggie {
public:
	sf::Sprite player;
	sf::Texture playerTexture;

	int ballRadius = 20;

	void update();
	void movement();
	void jump();
	void init();
	void render(sf::RenderWindow& window);

	sf::Vector2f playerPos;
	sf::Vector2f playerVelocity;
	int jumpHeight = 25;
	float gravity = 0.5;
	float speed = 8;
	bool readyToJump = false;

	sf::Sprite platformSprite;
	sf::Texture platformTexture;

private:


};