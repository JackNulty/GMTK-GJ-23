#include "Veggie.h"

void Veggie::update()
{
	if (player.getGlobalBounds().intersects(platformSprite.getGlobalBounds()))
	{
		playerVelocity.y = 0;
		gravity = 0;
		readyToJump = true;
	}
	else gravity = 0.5;
}

void Veggie::movement()
{
	playerVelocity.y += gravity;
	playerPos.y += playerVelocity.y;

	if (playerPos.y >= SCREEN_HEIGHT - ballRadius)
	{
		playerPos.y = SCREEN_HEIGHT - ballRadius;
		readyToJump = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		jump();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (playerPos.x <= 0 + ballRadius)
		{
			playerPos.x = 0 + ballRadius;
		}
		else
		{
			playerPos.x -= speed;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (playerPos.x >= SCREEN_WIDTH - ballRadius)
		{
			playerPos.x = SCREEN_WIDTH - ballRadius;
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
