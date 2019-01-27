#include "Player.h"


player::player() :
	m_move(false)
{
}

player::~player()
{
}

void player::update(sf::Time dt)
{
	animation();
	movement(dt);

	m_controller.update();
}

//initilize the player
void player::init()
{
	if (!playerTexture.loadFromFile("resources\\images\\Characters\\player.png"))
	{
		std::cout << "error opening player image" << std::endl;
	}
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(xPosSprite, yPosSprite, rectWidth, rectHeight));
	playerSprite.setScale(5, 5);
	playerSprite.setOrigin(rectWidth / 2.0f, rectHeight / 2.0f);
	playerSprite.setPosition(850, 600);
}

void player::draw(sf::RenderWindow& m_window)
{
	m_window.draw(playerSprite);
}

void player::animation()
{
	animationTimer++;

	if (m_controller.m_currentState.LeftThumbStick.x > 0)
	{
		rectWidth = -25;
	}
	else if (m_controller.m_currentState.LeftThumbStick.x < 0)
	{
		rectWidth = 25;
	}

	if ((animationTimer % 5) == 0)
	{
		xPosSprite += 32;
	}
	else if (xPosSprite >= 288 && rectWidth > 0)
	{
		xPosSprite = 0;
		animationTimer = 0;
	}
	else if(xPosSprite >= 288 && rectWidth < 0)
	{
		xPosSprite = 32;
		animationTimer = 0;
	}

	playerSprite.setTextureRect(sf::IntRect(xPosSprite, yPosSprite, rectWidth, rectHeight));
}

void player::movement(sf::Time dt)
{
	
	if (currentState != ground)
	{
		playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2f((m_velocity * time)) + (0.5f * m_gravity * (time * time)));
		m_velocity = m_velocity + (m_gravity * time);
	}
	else
	{
		playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2f((m_velocity * time)) + (0.5f * m_acceleration * (time * time)));
		m_velocity = m_velocity + (m_acceleration * time);
	}


	if (m_controller.isConnected() == true)
	{
		if (m_controller.m_currentState.LeftThumbStick.x >= 50 || m_controller.m_currentState.LeftThumbStick.x <= -50)
		{
			m_move = true;
		}

		if (m_move)
		{
			m_velocity.x = m_controller.m_currentState.LeftThumbStick.x/ 3;

			m_acceleration = m_gravity.y * sf::Vector2f(m_velocity.x, m_velocity.y);
		}

		if (playerSprite.getPosition().y > 1800 && currentState == falling)
		{
			m_velocity.y = 0;
			m_acceleration.y = 0; 
			currentState = ground;
		}

		if (currentState != falling && currentState != jump)
		{
			if (m_controller.m_currentState.A == true)
			{
				m_velocity.y = -80;
				m_acceleration.y = -80;
				currentState = falling;
			}
		}
	}

	std::cout << playerSprite.getPosition().x << std::endl;
	if (playerSprite.getPosition().x <= 750 + (playerSprite.getTextureRect().width * 3) )
	{
		playerSprite.setPosition(playerSprite.getPosition() + sf::Vector2f{ 1.0f,0.0f });
		m_velocity.x = 0;
		m_acceleration.x = 0;
	}
	if (playerSprite.getPosition().x >= (SCREEN_WIDTH * 3) - 750 + (playerSprite.getTextureRect().width * 3))
	{
		playerSprite.setPosition(playerSprite.getPosition() - sf::Vector2f{ 1.0f,0.0f });
		m_velocity.x = 0;
		m_acceleration.x = 0;
	}
}

sf::Vector2f player::getPos()
{
	return playerSprite.getPosition();
}
