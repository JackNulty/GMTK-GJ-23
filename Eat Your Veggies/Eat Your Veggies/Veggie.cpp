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
	movement();
	player.setPosition(playerPos.x, playerPos.y);
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
		std::cout << "jump\n";
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

void Veggie::init()
{
	if (!playerTexture.loadFromFile("ASSETS/SPRITES/char.png"))
	{
		std::cout << "Error with player texture";
	}
	player.setTexture(playerTexture);
	playerPos.x = SCREEN_WIDTH / 2;
	playerPos.y = 100;
	player.setScale(1, 1);
	player.setOrigin(100, 100);
	

	if (!platformTexture.loadFromFile("ASSETS/SPRITES/char.png"))
	{
		std::cout << "Platform failed to load";
	}

	platformSprite.setTexture(platformTexture);
	platformSprite.setPosition(200, 500);
	platformSprite.setScale(1, 1);
	platformSprite.setOrigin(150, 25);
	platformSprite.setColor(sf::Color(0, 0, 0, 255));
}

void Veggie::render(sf::RenderWindow& window)
{
	window.clear(sf::Color{ 100,100,100,255 });
	window.draw(player);
	window.draw(platformSprite);
	window.display();
}
