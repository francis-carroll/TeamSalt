#include "GamePlay.h"

GamePlay::GamePlay()
{
}

GamePlay::~GamePlay()
{
}

void GamePlay::initialise(sf::Font & t_font)
{
	m_player.init();
}

void GamePlay::render(sf::RenderWindow & t_window)
{
	m_player.draw(t_window);
}

void GamePlay::update(sf::Time dt)
{
	m_player.update(dt);
}

void GamePlay::setupText()
{
}

void GamePlay::setupSprite()
{
}
