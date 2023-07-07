#include "Game.h"

Game::Game() :
    m_window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT, 32), "Eat Your Beggies", sf::Style::Default)
{
    init();
}

void Game::run()
{
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Clock clockForFrameRate;
	clockForFrameRate.restart();
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}
		timeSinceLastUpdate += clockForFrameRate.restart();
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}
}

void Game::init()
{
    myVeg.init();
	myLevel.init();
}

void Game::render()
{
    myVeg.render(m_window);
	myLevel.render(m_window);
}

void Game::update()
{
    myVeg.update();
	myLevel.update();
    render();
}
