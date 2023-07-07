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
	if (!backgroundTexture.loadFromFile("ASSETS/SPRITES/kitchen.jpg"))
	{
		std::cout << "error" << std::endl;
	}
	background.setTexture(backgroundTexture);
	background.setScale(0.8, 0.6);
    myVeg.init();
	myLevel.init();
	myHud.init();
	myChef.init();
}

void Game::render()
{
	m_window.clear(sf::Color{ 255,255,255,255 });
	m_window.draw(background);
	myChef.render(m_window);
	myLevel.render(m_window);
	myHud.render(m_window);
	myVeg.render(m_window);
	m_window.display();
}

void Game::update()
{
    myVeg.update();
	myLevel.update();
	myChef.update();
    render();
	collision();
}

void Game::collision()
{
	if (myLevel.handleCollisons(myVeg.player) == true)
	{
		std::cout << "hiding\n";
	}
}
