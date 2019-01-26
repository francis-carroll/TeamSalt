#include "GamePlay.h"

GamePlay::GamePlay()
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
	t_window.clear();
	m_level1.render(t_window);
	m_player.draw(t_window);
	t_window.display();
}

void GamePlay::update(sf::Time dt)
{
	m_level1.update(dt);
	m_player.update(dt);
}

void GamePlay::setupText()
{
}

void GamePlay::setupSprite()
{
}
