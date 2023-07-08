#include "Chef.h"


void Chef::init()
{
	std::srand(time(NULL));

	if (!chefUnawareTexture.loadFromFile("ASSETS/SPRITES/chefUnawareUpdated.png"))
	{
		std::cout << "Error loading chef back turnt texture\n";
	}
	if (!chefCuriousTexture.loadFromFile("ASSETS/SPRITES/chefTurningUpdated.png"))
	{
		std::cout << "Error loading chef turning texture\n";
	}
	if (!chefStaringTexture.loadFromFile("ASSETS/SPRITES/chefStaringUpdated.png"))
	{
		std::cout << "Error loading chef staring texture\n";
	}
	if (!huh.loadFromFile("ASSETS/AUDIO/huh.ogg"))
	{
		std::cout << "error laoding huh? audio\n";
	}

	chefNoise.setBuffer(huh);

	bandroot.setTexture(chefUnawareTexture);
	bandroot.setOrigin(213, 160);
	bandroot.setScale(1.8, 1.8);
	bandroot.setPosition(600, 300);
	turnThreshold = rand() % 420+80;
}

void Chef::render(sf::RenderWindow& window)
{
	window.draw(bandroot);
}

void Chef::update()
{
	// Constantly add 1 every update
	turnTimer += 1;

	// Changes to looking over the shoulder 1.5 seconds before turning
	if (turnTimer >= turnThreshold - 90)
	{
		bandroot.setTexture(chefCuriousTexture);
		bandroot.setTextureRect(sf::IntRect(0,0,273,279));
		bandroot.setOrigin(137, 120);
		facingPlayer = false;
		if (gawking == true)
		{
			gawking = false;
			chefNoise.play();
		}
	}
	// If the timers up, turn around
	if (turnTimer >= turnThreshold)
	{
		bandroot.setTexture(chefStaringTexture);
		bandroot.setTextureRect(sf::IntRect(0, 0, 454, 388));
		bandroot.setOrigin(227, 184);
		facingPlayer = true;
	}
	if (turnTimer > turnThreshold + 240)
	{
		turnTimer = 0;
		turnThreshold = rand() % 480;
		bandroot.setTexture(chefUnawareTexture);
		gawking = true;
		bandroot.setTextureRect(sf::IntRect(0, 0, 425, 320));
		bandroot.setOrigin(213, 160);
		facingPlayer = false;
	}

	//std::cout << turnThreshold << "\n";
}
