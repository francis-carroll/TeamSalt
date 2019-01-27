
#include "enemy.h"

Enemy::Enemy() :
	enemyState{ walking }
{

}

void Enemy::init()
{
	if (!m_PoliceTexture.loadFromFile("resources\\images\\characters\\policemanSpriteSheet.png"))
	{
		std::cout << "error loading police man sprite";
	}
	m_enemySprite.setTexture(m_PoliceTexture);

	m_enemySprite.setTextureRect(sf::IntRect(m_enemyXPos, m_enemyYPos, m_textureWidth, m_textureHeight));
	m_enemySprite.setOrigin(m_textureWidth / 2.0, m_textureHeight / 2.0);
	m_enemySprite.setScale(4,4);

	m_enemySprite.setPosition(1500, 1200);
}

void Enemy::draw(sf::RenderWindow & m_window)
{
	m_window.draw(m_enemySprite);
}

void Enemy::update()
{
	animation();
	move();
}

void Enemy::move()
{
	m_enemySprite.setPosition(m_enemySprite.getPosition() + sf::Vector2f((m_velocity * time)) + (0.5f * GRAVITY * (time * time)));
	//m_velocity = m_velocity + (GRAVITY * time);
}

void Enemy::animation()
{
	m_animationTimer++;

	if ((m_animationTimer % 15) == 0)
	{
		m_enemyXPos += 21;
	}
	else if (m_enemyXPos >= 60 && m_textureWidth > 0)
	{
		m_animationTimer = 0;
		m_enemyXPos = 0;
	}

	m_enemySprite.setTextureRect(sf::IntRect(m_enemyXPos, m_enemyYPos, m_textureWidth, m_textureHeight));
}
