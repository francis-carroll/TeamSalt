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
	for (int i = 0; i < MAX_TILES; i++)
	{
		m_groundTiles[i].render(t_window);
	}
}

void Level::update(sf::Time dt)
{
}

void Level::setupSprite()
{
	/*if (!m_bgLayer1Tex.loadFromFile("resources/images/backgrounds/cityScape3.png"))
	{
		std::cout << "Error loading bglayer3" << std::endl;
	}
	if (!m_bgLayer2Tex.loadFromFile("resources/images/backgrounds/cityScape2.png"))
	{
		std::cout << "Error loading bglayer2" << std::endl;
	}
	if (!m_bgLayer3Tex.loadFromFile("resources/images/backgrounds/cityScape1.png"))
	{
		std::cout << "Error loading bglayer1" << std::endl;
	}
	if (!m_skyTex.loadFromFile("resources/images/backgrounds/sky.png"))
	{
		std::cout << "Error loading skyTex" << std::endl;
	}
	m_sky.setTexture(m_skyTex);
	m_sky.setScale(2, 2);
	m_bgLayer1.setTexture(m_bgLayer1Tex);
	m_bgLayer1.setScale(2, 2);
	m_bgLayer1.setPosition(sf::Vector2f{ -10.0f,-1000.0f });
	m_bgLayer2.setTexture(m_bgLayer2Tex);
	m_bgLayer2.setScale(2, 2);
	m_bgLayer2.setPosition(sf::Vector2f{ 40.0f,-900.0f });
	m_bgLayer3.setTexture(m_bgLayer3Tex);
	m_bgLayer3.setScale(2, 2);
	m_bgLayer3.setPosition(sf::Vector2f{ 0.0f,-800.0f });*/
	if (!m_texture.loadFromFile("resources/images/backgrounds/level1Screen.png"))
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
	for (int i = 0; i < MAX_TILES; i++)
	{
		if (i != 0 && m_groundTiles[i - 1].getPosition().x < 6310)
		{
			m_groundTiles[i].setPosition(sf::Vector2f{ 164.0f * i, 1900 });
		}
	}
}
