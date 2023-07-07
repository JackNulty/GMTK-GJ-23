#include "HUD.h"
void HUD::init()
{
	if (!barsTexture.loadFromFile("ASSETS/SPRITES/bars.png"))
	{
		std::cout << "Error loading bars texture";
	}
	rageBar.setTexture(barsTexture);
	progressBar.setTexture(barsTexture);
	rageBar.setTextureRect(sf::IntRect(0, 0, 290, 101));
	progressBar.setTextureRect(sf::IntRect(0, 111, 293, 113));

	progressBar.setPosition(SCREEN_WIDTH - 295, 0);
}

void HUD::render(sf::RenderWindow& window)
{
	window.draw(rageBar);
	window.draw(progressBar);
}
