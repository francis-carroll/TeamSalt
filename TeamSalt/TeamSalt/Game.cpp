#include "Game.h"
#include <iostream>

GameMode Game::m_currentMode{ GameMode::Licence };

Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "Mimi" },
	m_exitGame{ false }
{
	try
	{
		LevelLoader::load(1, m_level);
	}
	catch (std::exception & e)
	{
		std::cout << "failure loading the level" << std::endl;
		std::cout << e.what() << std::endl;
		throw e;
	}
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps

	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}

		
	}
}


void Game::update(sf::Time t_deltaTime)
{
	srand((unsigned)time(nullptr));

	switch (m_currentMode)
	{
	case GameMode::Licence:
		break;
	case GameMode::Splash:
		break;
	default:
		break;
	}
}

void Game::render()
{
	switch (m_currentMode)
	{
	case GameMode::Licence:
		break;
	case GameMode::Splash:
		break;
	default:
		break;
	}
}