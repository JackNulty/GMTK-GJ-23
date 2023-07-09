#include "Veggie.h"

void Veggie::update()
{
	movement();
}

void Veggie::movement()
{
	player.setPosition(playerPos.x, playerPos.y);
	playerVelocity.y += gravity;
	playerPos.y += playerVelocity.y;
	playerPos.x-=gameSpeed;
	if (playerPos.y >= SCREEN_HEIGHT - 200)
	{
		playerPos.y = SCREEN_HEIGHT - 200;
		readyToJump = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		jump();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playerPos.x -= speed;
		//if (playerPos.x <= 0)
		//{
		//	playerPos.x = 0;
		//}
		//else
		//{
		//	playerPos.x -= speed;
		//}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (playerPos.x >= SCREEN_WIDTH - 8)
		{
			playerPos.x = SCREEN_WIDTH;
		}
		else
		{
			playerPos.x += speed;
		}
	}
}

void Veggie::jump()
{
	if (readyToJump == true)
	{
		playerVelocity.y = -jumpHeight;
		readyToJump = false;
	}
}

void Veggie::init()
{
	if (!playerTexture.loadFromFile("ASSETS/SPRITES/Carrot.png"))
	{
		std::cout << "Error with player texture";
	}
	player.setTexture(playerTexture);
	playerPos.x = SCREEN_WIDTH / 2;
	playerPos.y = 300;
	player.setScale(4, 4);
	player.setOrigin(16, 23);
}

void Veggie::render(sf::RenderWindow& window)
{
	window.draw(player);
	
}

void Veggie::increaseSpeed(int newSpeed)
{
	gameSpeed = newSpeed;
}

void Veggie::resetPlayer()
{
	playerPos.x = SCREEN_WIDTH / 2;
	playerPos.y = 300;
	player.setPosition(playerPos);
}