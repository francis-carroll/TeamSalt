#include "GamePlay.h"

GamePlay::GamePlay() :
	m_view(sf::FloatRect{ 0,0,1600,1200 })
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::initialise(sf::Font & t_font)
{
	m_level1.initialise(t_font);
	m_player.init();
}

void GamePlay::render(sf::RenderWindow & t_window)
{
	t_window.setView(m_view);
	t_window.clear();
	m_level1.render(t_window);
	m_player.draw(t_window);
	t_window.display();
}

void GamePlay::update(sf::Time dt)
{
	m_level1.update(dt);
	m_player.update(dt);
	checkPlayerCollision();
	m_view.setCenter(m_player.getPos());

}

void GamePlay::setupText()
{
}

void GamePlay::setupSprite()
{
}

void GamePlay::checkPlayerCollision()
{
	for (int i = 0; i < 36; i++)
	{
		if (m_player.getSprite().getGlobalBounds().intersects(m_level1.m_groundTiles[i].getSprite().getGlobalBounds()))
		{
			m_player.isOnGround(m_player.getPos());
			break;
		}
		else
		{
			m_player.isFalling();
		}
	}
}
