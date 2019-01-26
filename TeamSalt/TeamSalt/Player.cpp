#include "Player.h"

player::player()
{
}

player::~player()
{
}

void player::update()
{
	animation();
}

//initilize the player
void player::init()
{
	if (!playerTexture.loadFromFile("ASSETS\\IMAGES\\Characters\\player.png"))
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
	else if (xPosSprite >= 320)
	{
		xPosSprite = 0;
	}

	playerSprite.setTextureRect(sf::IntRect(xPosSprite, yPosSprite, 25, 33));
}
