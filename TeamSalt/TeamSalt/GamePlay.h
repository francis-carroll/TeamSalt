#ifndef GAMEPLAY
#define GAMEPLAY

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"
#include <iostream>

class GamePlay
{
public:
	GamePlay();
	~GamePlay();

	void initialise(sf::Font &t_font);
	void render(sf::RenderWindow &t_window);
	void update(sf::Time dt);
private:
	void setupText();
	void setupSprite();
	void checkPlayerCollision();

	sf::View m_view;
	player m_player;
	Enemy m_enemy;
	Level m_level1;
};

#endif
