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
	if (!gameOverTexture.loadFromFile("ASSETS/SPRITES/lose.jpg"))
	{
		std::cout << "error" << std::endl;
	}
	gameOverSprite.setTexture(gameOverTexture);

	if (!gameWinTexture.loadFromFile("ASSETS/SPRITES/veggieWinScreen.png"))
	{
		std::cout << "error" << std::endl;
	}
	gameWinSprite.setTexture(gameWinTexture);

	if (!levelCompleteTex.loadFromFile("ASSETS/SPRITES/LevelCompletedPlaceholder.png"))
	{
		std::cout << "level complete screen failed to load";
	}
	levelCompleteSprite.setTexture(levelCompleteTex);

	if (!splashScreen.loadFromFile("ASSETS/SPRITES/splashScreen.png"))
	{
		std::cout << "Splash screen failed to load";
	}
	introCards.setTexture(splashScreen);
	if (!tutorialHide.loadFromFile("ASSETS/SPRITES/tutorialImageHide.png"))
	{
		std::cout << "tutorial hide screen failed to load";
	}
	if (!tutorialLevel.loadFromFile("ASSETS/SPRITES/tutorialImageProg.png"))
	{
		std::cout << "tutorial level screen failed to load";
	}
	if (!tutorialRage.loadFromFile("ASSETS/SPRITES/tutorialImageRage.png"))
	{
		std::cout << "tutorial rage screen failed to load";
	}



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
	if (levelCompleted == true)
	{
		m_window.draw(levelCompleteSprite);
		myVeg.resetPlayer();
	}
	if (gameOver == true)
	{
		m_window.draw(gameOverSprite);
	}
	if (levelNo == 3 && gameOver !=true)
	{
		m_window.draw(gameWinSprite);
	}
	m_window.draw(introCards);
	m_window.display();
}

void Game::update()
{
	if (gameStarted == false)
	{
		spaceCooldown--;
		if (spaceCooldown < 0)
		{
			spaceCooldown = 0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&spaceCooldown == 0)
		{
			spaceCooldown = cooldownMax;
			cardNo++;
		}
		if (cardNo == 0)
		{
			introCards.setTexture(splashScreen);
		}
		if (cardNo == 1)
		{
			introCards.setTexture(tutorialHide);
		}
		if (cardNo == 2)
		{
			introCards.setTexture(tutorialLevel);
		}
		if (cardNo == 4)
		{
			introCards.setTexture(tutorialRage);
		}
		if (cardNo == 5)
		{
			introCards.setPosition(-1000, -1000);
			gameStarted = true;
		}
	}
	if (gameStarted == true)
	{
		myVeg.update();
		myLevel.update();
		if (gameOver == false || levelNo != 3)
		{
			myChef.update();
		}
		levelDistance = levelDistance + 0.075;
		levelBarSize = levelDistance;
		levelBar.setSize(sf::Vector2f(levelBarSize, 60));
		if (myChef.facingPlayer == true && inCover == false)
		{
			rageMeter = rageMeter + 0.5;
		}
		//std::cout << rageMeter << std::endl;
		if (rageMeter >= 230 || myVeg.player.getPosition().x <= -50)
		{
			gameOver = true;
			rageMeter = 230;
		}
		if (gameOver == true)
		{
			std::cout << "game over" << std::endl;
		}
		levelCompleted = false;
		if (levelDistance >= 280)
		{
			gameWin = true;
			levelPopupCounter--;
			if (levelPopupCounter >= 0)
			{
				std::cout << "well done level passed" << std::endl;
				levelCompleted = true;
			}
			if (levelPopupCounter <= 0)
			{
				levelDistance = 0;
				rageMeter = 0;
				levelPopupCounter = 240;
				gameWin = false;
				increaseGameSpeed();
			}
		}
		rageBarSize = rageMeter;
		rageBar.setSize(sf::Vector2f(rageBarSize, 60));
		
		collision();
	}
	render();
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

void Game::increaseGameSpeed()
{
	levelNo++;
	if (levelNo == 1)
	{
		gameSpeed = midSpeed;
		myVeg.increaseSpeed(gameSpeed);
		myLevel.increaseSpeed(gameSpeed);
	}
	if (levelNo == 2)
	{
		gameSpeed = maxSpeed;
		myVeg.increaseSpeed(gameSpeed);
		myLevel.increaseSpeed(gameSpeed);
	}
}