#pragma once

#include <SFML/Graphics.hpp>
#include "Controller.h"

class player
{
public:
	player();
	~player();

	void update(sf::Time dt);

	void init();

	void draw(sf::RenderWindow& m_window);

	void animation();

	void movement(sf::Time dt);

private:

	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	Xbox360Controller m_controller;

	float xPosSprite{ 0 };
	float yPosSprite{ 0 };

	int animationTimer{ 0 };

	const sf::Vector2f m_gravity{ 0, 9.8 };

	sf::Vector2f m_velocity{ 0,0 };

	float time{ 1.0f / 60.0f };

};
