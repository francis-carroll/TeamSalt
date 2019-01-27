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
	playerBox.setPosition(playerSprite.getPosition());

	animation();
		
	if (m_controller.m_currentState.X == true)
	{
		playerSprite.setTexture(playerBoxTex);
		xPosSprite = 0;
		yPosSprite = 0;
		rectWidth = 90;
		rectHeight = 90;
		playerSprite.setScale(0.5, 0.5);
		playerSprite.setOrigin(rectWidth / 2, rectHeight / 2);
		scale = 1;
		playerSprite.setTextureRect(sf::IntRect(xPosSprite, yPosSprite, rectWidth, rectHeight));
	}
	else
	{
		playerSprite.setTexture(playerTexture);
		rectWidth = 13;
		rectHeight = 10;
		scale = 0;
		playerSprite.setTextureRect(sf::IntRect(xPosSprite, yPosSprite, rectWidth, rectHeight));
		playerSprite.setOrigin(rectWidth / 2.0f, rectHeight / 2.0f);

		movement(dt);
	}

	if (scale == 0)
	{
		playerSprite.setScale(5, 5);
	}
	if (scale == 1)
	{
		playerSprite.setScale(0.5, 0.5);
	}

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

	if (!playerBoxTex.loadFromFile("resources\\images\\Characters\\slimeAlt.png"))
	{
		std::cout << "error opening player box" << std::endl;
	}

	playerBox.setTexture(playerBoxTex);
	playerBox.setScale(5, 5);
	playerBox.setOrigin(playerBox.getGlobalBounds().width / 2.0f, playerBox.getGlobalBounds().height / 2.0f);
	playerBox.setPosition(0, 0);
}

void player::draw(sf::RenderWindow& m_window)
{
	m_window.draw(playerBox);
	m_window.draw(playerSprite);
}

void player::animation()
{
	animationTimer++;

	if (m_controller.m_currentState.LeftThumbStick.x > 0)
	{
		rectWidth = -13;
	}
	else if (m_controller.m_currentState.LeftThumbStick.x < 0)
	{
		rectWidth = 13;
	}

	if ((animationTimer % 5) == 0)
	{
		xPosSprite += 13;
	}
	else if (xPosSprite >= 118 && rectWidth > 0)
	{
		xPosSprite = 0;
		animationTimer = 0;
	}
	else if(xPosSprite >= 131-13 && rectWidth < 0)
	{
		xPosSprite = 13;
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
		playerBox.setPosition(playerSprite.getPosition());
		if (m_controller.m_currentState.LeftThumbStick.x >= 50 || m_controller.m_currentState.LeftThumbStick.x <= -50)
		{
			m_move = true;
		}

		if (m_move)
		{
			m_velocity.x = m_controller.m_currentState.LeftThumbStick.x/ 3;

			m_acceleration = m_gravity.y * sf::Vector2f(m_velocity.x, m_velocity.y);
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

	std::cout << playerSprite.getPosition().y << std::endl;
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

void player::isOnGround(sf::Vector2f t_pos)
{
	m_previousPos = t_pos;
	m_velocity.y = 0;
	m_acceleration.y = 0;
	m_acceleration.x = 0;
	currentState = playerstate::ground;
	playerSprite.setPosition(m_previousPos - sf::Vector2f{0.0f,0.3f});
}

void player::isFalling()
{
	currentState = playerstate::falling;
}

sf::Vector2f player::getPos()
{
	return playerSprite.getPosition();
}
