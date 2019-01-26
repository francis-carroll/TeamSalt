#include "Player.h"

player::player()
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
	playerSprite.setPosition(800, 600);
}

void player::draw(sf::RenderWindow& m_window)
{
	m_window.clear();
	m_window.draw(playerSprite);
	m_window.display();
}

void player::animation()
{
	animationTimer++;

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
	

	playerSprite.setPosition(playerSprite.getPosition() + (m_velocity * time) + (0.5f * m_gravity * (time * time)));
	
	m_velocity = m_velocity + (m_gravity * time);
	

	if (m_controller.isConnected() == true)
	{
		if (m_controller.m_currentState.LeftThumbStick.x != 0)
		{
			m_velocity.x = m_controller.m_currentState.LeftThumbStick.x / 2;
		}

		if (m_controller.m_currentState.LeftThumbStick.x > 0)
		{
			rectWidth = -25;
		}
		else if (m_controller.m_currentState.LeftThumbStick.x < 0)
		{
			rectWidth = 25;
		}

		if (currentState != falling && currentState != jump)
		{
			if (m_controller.m_currentState.A == true)
			{
				m_velocity.y = -50;
				currentState = falling;
			}
		}
	}

	if (playerSprite.getPosition().y >= SCREEN_HEIGHT - (playerSprite.getTextureRect().height * 3) && m_velocity.y > 0)
	{
		m_velocity.y = 0;
		currentState = ground;
	}
	if (playerSprite.getPosition().x <= 0 - (playerSprite.getTextureRect().width * 3))
	{
		;
	}
}
