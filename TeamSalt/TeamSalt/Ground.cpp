#include "Ground.h"

Ground::Ground() :
	m_pos{ 1000,1000 }
{
}

Ground::~Ground()
{
}

void Ground::initialise(sf::Font & t_font)
{
	setupSprite();
}

void Ground::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_sprite);
}

void Ground::update(sf::Time dt)
{
}

void Ground::setPosition(sf::Vector2f t_pos)
{
	m_pos = t_pos;
	m_sprite.setPosition(m_pos);
}

sf::Vector2f Ground::getPosition()
{
	return m_pos;
}


void Ground::setupSprite()
{
	if (!m_spriteTex.loadFromFile("resources/images/backgrounds/groundTile.png"))
	{
		std::cout << "Error loading greound tex" << std::endl;
	}
	m_sprite.setTexture(m_spriteTex);
	m_sprite.setScale(2, 2);
	m_sprite.setPosition(m_pos);
}
