#pragma once

#include <SFML/Graphics.hpp>
#include "Controller.h"

class player
{
public:
	player();
	~player();

	void update();

	void init();

	void draw(sf::RenderWindow& m_window);

	void animation();

private:

	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	float xPosSprite{ 0 };
	float yPosSprite{ 0 };

	int animationTimer{ 0 };


};
