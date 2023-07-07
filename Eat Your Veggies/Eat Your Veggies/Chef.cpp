#include "Chef.h"


void Chef::init()
{
	std::srand(time(NULL));

	if (!chefUnawareTexture.loadFromFile("ASSETS/SPRITES/backTurnedChefTemp.png"))
	{
		std::cout << "Error loading chef back turnt texture";
	}
	if (!chefCuriousTexture.loadFromFile("ASSETS/SPRITES/turningChefTemp.png"))
	{
		std::cout << "Error loading chef turning texture";
	}
	if (!chefStaringTexture.loadFromFile("ASSETS/SPRITES/turnedAroundChefTemp.png"))
	{
		std::cout << "Error loading chef turning texture";
	}
	bandroot.setTexture(chefUnawareTexture);
	turnThreshold = rand() % 480;
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
	}
	// If the timers up, turn around
	if (turnTimer >= turnThreshold)
	{
		bandroot.setTexture(chefStaringTexture);
	}
	if (turnTimer > turnThreshold + 240)
	{
		turnTimer = 0;
		turnThreshold = rand() % 480;
		bandroot.setTexture(chefUnawareTexture);
	}

	std::cout << turnThreshold << "\n";
}
