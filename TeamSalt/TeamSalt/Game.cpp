#include "Game.h"
#include <iostream>

GameMode Game::m_currentMode{ GameMode::Splash };

Game::Game() :
	m_window{ sf::VideoMode{ 1600, 1200, 32 }, "Mimi" },
	m_exitGame{ false }
{
	setup();
	m_splashScreen.initialise(m_font);
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

void Game::setup()
{
	if (!m_font.loadFromFile("ASSETS/FONTS/font.ttf"))
	{
		std::cout << "Error loading font file" << std::endl;
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

		/*switch (m_currentMode)
		{
		
		}*/
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
		m_splashScreen.update(t_deltaTime);
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
		m_splashScreen.draw(m_window);
		break;
	default:
		break;
	}
}