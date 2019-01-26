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
	m_enemy.init();
}

void GamePlay::render(sf::RenderWindow & t_window)
{
	t_window.clear();
	m_player.draw(t_window);
	m_enemy.draw(t_window);
	t_window.display();
}

void GamePlay::update(sf::Time dt)
{
	m_player.update(dt);
	m_enemy.update();
}

void GamePlay::setupText()
{
}

void GamePlay::setupSprite()
{
}
