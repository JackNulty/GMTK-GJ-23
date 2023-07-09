#pragma once
#include "Globals.h"

class Veggie {
public:
	void update();
	void movement();
	void jump();
	void init();
	void render(sf::RenderWindow& window);
	sf::Sprite player;
	sf::Texture playerTexture;


	void increaseSpeed(int newSpeed);

	void resetPlayer();
private:
	
	int ballRadius = 20;
	sf::Vector2f playerPos;
	sf::Vector2f playerVelocity;
	int jumpHeight = 17;
	float const DEFAULT_GRAVITY = 0.5;
	float gravity = DEFAULT_GRAVITY;
	float speed = 8;
	bool readyToJump = false;
	int gameSpeed = minSpeed;
};