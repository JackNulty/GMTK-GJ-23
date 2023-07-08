#include "Chef.h"


void Chef::init()
{
	std::srand(time(NULL));

	if (!chefUnawareTexture.loadFromFile("ASSETS/SPRITES/chefUnawareUpdated.png"))
	{
		std::cout << "Error loading chef back turnt texture";
	}
	if (!chefCuriousTexture.loadFromFile("ASSETS/SPRITES/chefTurningUpdated.png"))
	{
		std::cout << "Error loading chef turning texture";
	}
	if (!chefStaringTexture.loadFromFile("ASSETS/SPRITES/chefStaringUpdated.png"))
	{
		std::cout << "Error loading chef turning texture";
	}
	bandroot.setTexture(chefUnawareTexture);
	bandroot.setOrigin(213, 160);
	bandroot.setPosition(400, 200);
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
		bandroot.setOrigin(137, 140);
		facingPlayer = false;
	}
	// If the timers up, turn around
	if (turnTimer >= turnThreshold)
	{
		bandroot.setTexture(chefStaringTexture);
		bandroot.setOrigin(227, 194);
		facingPlayer = true;
	}
	if (turnTimer > turnThreshold + 240)
	{
		turnTimer = 0;
		turnThreshold = rand() % 480;
		bandroot.setTexture(chefUnawareTexture);
		bandroot.setOrigin(213, 160);
		facingPlayer = false;
	}

	//std::cout << turnThreshold << "\n";
}
