
#include "enemy.h"

Enemy::Enemy() :
	enemyState{ walking }
{

}

void Enemy::init()
{
	if (!m_bodyTexutre.loadFromFile("resources//images//characters//policemanSprite.png"))
	{
		std::cout << "error loading police man sprite";
	}
	m_body.setTexture(m_bodyTexutre);
	m_body.setTextureRect(sf::IntRect(m_enemyXPos, m_enemyYPos, m_textureWidth, m_textureHeight));
	m_body.setOrigin(m_textureWidth / 2.0, m_textureHeight / 2.0);
	m_body.setScale(xScaler, xScaler);
	m_body.setPosition(1500, SCREEN_HEIGHT - (m_textureHeight * yScaler + m_textureHeight));
	m_velocity = { -2.0,0.0 };
}

void Enemy::draw(sf::RenderWindow & m_window)
{
	m_window.draw(m_body);
}

void Enemy::update()
{
	animation();
	move();
}

void Enemy::move()
{
	if (getPosition().x <= 20)
	{
		m_velocity.x *= -1;
		m_textureWidth = -20;
	}
	else if (getPosition().x > SCREEN_WIDTH - 80)
	{
		m_velocity.x *= -1;
		m_textureWidth = 20;
	}
	m_body.move(m_velocity);
}

void Enemy::animation()
{
	m_animationTimer++;
	if ((m_animationTimer % 15) == 0)
	{
		m_enemyXPos += 20;
	}
	else if (m_enemyXPos >= 60 && m_textureWidth > 0)
	{
		m_animationTimer = 0;
		m_enemyXPos = 0;
	}
	else if (m_enemyXPos >= 60 && m_textureWidth < 0)
	{
		m_animationTimer = 0;
		m_enemyXPos = 20;
	}
	m_body.setTextureRect(sf::IntRect(m_enemyXPos, m_enemyYPos, m_textureWidth, m_textureHeight));
}
