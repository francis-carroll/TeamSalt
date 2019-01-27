#pragma once

#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Globals.h"
#include "MyVector2D.h"
enum playerstate 
{
	ground,
	jump,
	hidden,
	falling
};

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
	void isOnGround(sf::Vector2f t_pos);
	void isFalling();

	sf::Vector2f getPos();
	void setPos(sf::Vector2f t_pos) { playerSprite.setPosition(t_pos); }
	sf::Sprite getSprite() { return playerSprite; }

private:

	sf::Sprite playerSprite;
	sf::Texture playerTexture;

	Xbox360Controller m_controller;


	float xPosSprite{ 0 };
	float yPosSprite{ 0 };
	float rectWidth{ 13 };
	float rectHeight{ 10 };

	int animationTimer{ 0 };

	const sf::Vector2f m_gravity{ 0, 9.8 };

	MyVector2D m_velocity{ 0,0 };

	sf::Vector2f m_acceleration{ 0,0 };
	sf::Vector2f m_previousPos;

	float time{ 1.0f / 5.0f };

	playerstate currentState{ falling };

	bool m_move;
};

