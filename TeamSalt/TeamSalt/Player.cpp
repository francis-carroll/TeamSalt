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
	playerSprite.setTextureRect(sf::IntRect(xPosSprite, yPosSprite, 25, 33));
	playerSprite.setScale(5, 5);
	playerSprite.setOrigin(12.5f, 16.5f);
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
	else if (xPosSprite >= 288)
	{
		xPosSprite = 0;
	}

	playerSprite.setTextureRect(sf::IntRect(xPosSprite, yPosSprite, 25, 33));
}

void player::movement(sf::Time dt)
{
	playerSprite.setPosition(playerSprite.getPosition() + (m_velocity * time) + (0.5f * m_gravity * (time * time)));
	m_velocity = m_velocity + (m_gravity * time);

	if (m_controller.isConnected() == true)
	{
		if (m_controller.m_currentState.LeftThumbStick.x != 0)
		{
			m_velocity = m_controller.m_currentState.LeftThumbStick;
		}
	}
}
