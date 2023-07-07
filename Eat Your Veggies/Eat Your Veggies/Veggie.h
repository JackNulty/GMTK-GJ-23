#pragma once
#include <SFML/Graphics.hpp> 

class Veggie{
public:
	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 700;


	sf::Sprite player;
	sf::Texture playerTexture;

	int ballRadius = 20;

	void update();
	void movement();
	void jump();

	sf::Vector2f playerPos;
	sf::Vector2f playerVelocity;
	int jumpHeight = 25;
	float gravity = 0.5;
	float speed = 8;
	bool readyToJump = false;

	sf::Sprite platformSprite;
	sf::Texture platformTexture;

private:


}
