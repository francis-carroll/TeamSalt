#ifndef GAMEPLAY
#define GAMEPLAY

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Player.h"
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

	player m_player;
};

#endif
