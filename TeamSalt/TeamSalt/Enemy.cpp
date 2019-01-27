
#include "enemy.h"

Enemy::Enemy() :
	enemyState{enemyState::hunting}
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
	if (enemyState != enemyState::walk)
	{
		m_enemySprite.setPosition(m_enemySprite.getPosition() + sf::Vector2f((m_velocity * time)) + (0.5f * GRAVITY * (time * time)));
		m_velocity = m_velocity + (GRAVITY * time);
	}
	else
	{
		m_enemySprite.setPosition(m_enemySprite.getPosition() + sf::Vector2f((m_velocity * time)) + (0.5f * m_acceleration * (time * time)));
		m_velocity = m_velocity + (m_acceleration * time);
	}

	
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

void Enemy::isOnGround()
{
	enemyState = enemyState::walk;
	m_enemySprite.setPosition(m_enemySprite.getPosition() - sf::Vector2f{ 0.0f,0.3f });
	m_velocity.y = 0;
	m_acceleration.y = 0;
}

void Enemy::falling()
{
	enemyState = enemyState::falling;
}
