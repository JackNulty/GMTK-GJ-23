#include "Game.h"

Game::Game() :
    m_window(sf::VideoMode(1024, 768, 32), "Eat Your Beggies", sf::Style::Default)
{
    init();
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    sf::Time timePerFrame = sf::seconds(1.0f / 60); // 60 fps
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        timeSinceLastUpdate += clock.restart();
        update(timePerFrame.asMilliseconds());

        if (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate = sf::Time::Zero;
        }
        render();
    }
}

void Game::init()
{
}

void Game::render()
{
}

void Game::update(double dt)
{
}
