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
	setupTiles();
	for (int i = 0; i < MAX_TILES; i++)
	{
		m_groundTiles[i].initialise(t_font);
	}
}

void Level::render(sf::RenderWindow & t_window)
{
	/*t_window.draw(m_sky);
	t_window.draw(m_bgLayer1);
	t_window.draw(m_bgLayer2);
	t_window.draw(m_bgLayer3);*/
	t_window.draw(m_background);
	for (int i = 0; i < 36; i++)
	{
		m_groundTiles[i].render(t_window);
	}
}

void Level::update(sf::Time dt)
{
}

void Level::setupSprite()
{
	if (!m_texture.loadFromFile("resources/images/backgrounds/level1Scrren.png"))
	{
		std::cout << "Error loading level1Screen" << std::endl;
	}
	m_background.setTexture(m_texture);
	m_background.setScale(2, 2);
	m_background.setPosition(sf::Vector2f{ 0.0,0.0});
}

void Level::setupText()
{
}

void Level::setupTiles()
{
	for (int i = 0; i < 36; i++)
	{
		if (i != 0 && m_groundTiles[i - 1].getPosition().x < 6310)
		{
			m_groundTiles[i].setPosition(sf::Vector2f{ 164.0f * i, 1783.0f });
		}
	}
}
