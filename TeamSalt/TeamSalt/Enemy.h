#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MyVector2D.h"
#include "Globals.h"


enum enemyState
{
	walking,
	hunting
};

class Enemy
{
public:
	Enemy();

	void init();

	void draw(sf::RenderWindow& m_window);

	void update();

	void move();

	void animation();

	sf::Vector2f getPosition() { return m_body.getPosition(); }
private:
	sf::Texture m_bodyTexutre; 
	sf::Sprite m_body;

	float m_enemyXPos{ 0 };
	float m_enemyYPos{ 0 };
	float m_textureWidth{ 20 };
	float m_textureHeight{ 29 };

	int xScaler{ 4 };
	int yScaler{ 4 };

	int m_animationTimer{ 0 };

	enemyState enemyState;

	MyVector2D m_velocity;

};