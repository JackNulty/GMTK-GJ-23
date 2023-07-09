#pragma once
#include "Globals.h"


class Chef
{
private:

	// Setting up Chef sprites
	sf::Sprite bandroot;
	// Looking towards player
	sf::Texture chefStaringTexture;
	// Looking over shoulder
	sf::Texture chefCuriousTexture;
	// Back turnt
	sf::Texture chefUnawareTexture;

	// Setting up chef turning around 

	int turnTimer = 0;
	int turnThreshold = 0;
	sf::SoundBuffer huh;
	sf::Sound chefNoise;
	sf::SoundBuffer whistle;
	sf::Sound shout;
	sf::SoundBuffer angry;
	// Chopping noise
	sf::SoundBuffer cutting;
	sf::Sound cuttingNoise;

	bool huhPlayable = true;
	bool whistlePlayable = true;
	bool angryPlayable = true;
public:

	void init();
	void render(sf::RenderWindow& window);
	void update();
	bool facingPlayer = false;

	bool stop = false;
};

