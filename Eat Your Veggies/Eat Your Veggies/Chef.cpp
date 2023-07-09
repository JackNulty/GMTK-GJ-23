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
	if (!whistle.loadFromFile("ASSETS/AUDIO/whistle.ogg"))
	{
		std::cout << "error laoding whistle audio\n";
	}
	if (!cutting.loadFromFile("ASSETS/AUDIO/cutting.ogg"))
	{
		std::cout << "error laoding cutting audio\n";
	}
	

	chefNoise.setBuffer(whistle);
	chefNoise.play();

	cuttingNoise.setBuffer(cutting);
	cuttingNoise.play();

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
		if (huhPlayable == true)
		{
			huhPlayable = false;
			chefNoise.setBuffer(huh);
			chefNoise.play();

			cuttingNoise.pause();

		}
	}
	// If the timers up, turn around
	if (turnTimer >= turnThreshold)
	{
		bandroot.setTexture(chefStaringTexture);
		bandroot.setTextureRect(sf::IntRect(0, 0, 454, 388));
		bandroot.setOrigin(227, 184);
		facingPlayer = true;

		whistlePlayable = true;
	}
	if (turnTimer > turnThreshold + 240)
	{
		turnTimer = 0;
		turnThreshold = rand() % 480;
		bandroot.setTexture(chefUnawareTexture);
		huhPlayable = true;
		bandroot.setTextureRect(sf::IntRect(0, 0, 425, 320));
		bandroot.setOrigin(213, 160);
		facingPlayer = false;

		if (whistlePlayable == true)
		{
			whistlePlayable = false;
			chefNoise.setBuffer(whistle);
			chefNoise.play();

			cuttingNoise.play();
		}
	}

}
