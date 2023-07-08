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
	if (!gameOverTexture.loadFromFile("ASSETS/SPRITES/gameOver.png"))
	{
		std::cout << "error" << std::endl;
	}
	gameOverSprite.setTexture(gameOverTexture);

	if (!gameWinTexture.loadFromFile("ASSETS/SPRITES/veggieWinScreen.png"))
	{
		std::cout << "error" << std::endl;
	}
	gameWinSprite.setTexture(gameWinTexture);

	rageBar.setFillColor(sf::Color(sf::Color::Red));
	rageBar.setSize(sf::Vector2f(rageBarSize,60));
	rageBar.setPosition(60, 36);

	levelBar.setFillColor(sf::Color(sf::Color::Blue));
	levelBar.setSize(sf::Vector2f(levelBarSize, 60));
	levelBar.setPosition(908, 42);

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
	m_window.draw(rageBar);
	m_window.draw(levelBar);
	myHud.render(m_window);
	myVeg.render(m_window);
	if (gameOver == true)
	{
		//m_window.draw(gameOverSprite);
	}
	if (gameWin == true)
	{
		m_window.draw(gameWinSprite);
	}
	m_window.display();
}

void Game::update()
{
    myVeg.update();
	myLevel.update();
	myChef.update();
	levelDistance = levelDistance + 0.1;
	levelBarSize = levelDistance;
	levelBar.setSize(sf::Vector2f(levelBarSize, 60));
	if (myChef.facingPlayer == true && inCover == false)
	{
		rageMeter = rageMeter + 0.1;
	}
	//std::cout << rageMeter << std::endl;
	if (rageMeter >= 230 || myVeg.player.getPosition().x <= -50)
	{
		gameOver = true;
	}
	if (gameOver == true)
	{
		std::cout << "game over" << std::endl;
	}
	if (levelDistance >= 280)
	{
		gameWin = true;
	}
	rageBarSize = rageMeter;
	rageBar.setSize(sf::Vector2f(rageBarSize, 60));
    render();
	collision();
}

void Game::collision()
{
	if (myLevel.handleCollisons(myVeg.player) == true)
	{
		inCover = true;
	}
	else {
		inCover = false;
	}
}
