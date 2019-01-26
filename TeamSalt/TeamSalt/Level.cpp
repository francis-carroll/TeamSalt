#include "Level.h"

Level::Level()
{
}

Level::~Level()
{
}

void Level::initialise(sf::Font & t_font)
{
	setupSprite();
}

void Level::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::White);
	t_window.draw(m_bgLayer1);
	t_window.draw(m_bgLayer2);
	t_window.draw(m_bgLayer3);
	t_window.display();
}

void Level::update(sf::Time dt)
{
}

void Level::setupSprite()
{
	if (!m_bgLayer1Tex.loadFromFile("resources/images/backgrounds/cityScape3.png"))
	{
		std::cout << "Error loading bglayer1" << std::endl;
	}
	if (!m_bgLayer2Tex.loadFromFile("resources/images/backgrounds/cityScape2.png"))
	{
		std::cout << "Error loading bglayer2" << std::endl;
	}
	if (!m_bgLayer3Tex.loadFromFile("resources/images/backgrounds/cityScape1.png"))
	{
		std::cout << "Error loading bglayer1" << std::endl;
	}
	m_bgLayer1.setTexture(m_bgLayer1Tex);
	m_bgLayer1.setPosition(sf::Vector2f{ -30.0f,-150.0f });
	m_bgLayer2.setTexture(m_bgLayer2Tex);
	m_bgLayer2.setPosition(sf::Vector2f{ 40.0f,-50.0f });
	m_bgLayer3.setTexture(m_bgLayer3Tex);
	m_bgLayer3.setPosition(sf::Vector2f{ 0.0f,0.0f });
}

void Level::setupText()
{
}
