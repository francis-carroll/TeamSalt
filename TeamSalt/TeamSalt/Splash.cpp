#include "Splash.h"

SplashScreen::SplashScreen() :
	m_playerRect(0, 0, 25, 33), m_timer{0}
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::initialise(sf::Font & t_font)
{
	m_font = t_font;
	setupText();
	setupSprite();
}

void SplashScreen::draw(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(m_background);
	t_window.draw(m_titleText);
	t_window.draw(m_continueText);
	t_window.draw(m_player);
	t_window.display();
}

void SplashScreen::update(sf::Time dt)
{
	m_timer++;
	if (m_timer >= 5)
	{
		if (m_playerRect.left >= 288)
		{
			m_timer = 0;
			m_playerRect.left = 0;
		}
		else
		{
			m_timer = 0;
			m_playerRect.left += 32;
		}
	}
	m_player.setTextureRect(m_playerRect);
}

void SplashScreen::setupText()
{
	m_continueText.setFont(m_font);
	m_continueText.setString("Press A to Continue");
	m_continueText.setCharacterSize(70);
	m_continueText.setFillColor(sf::Color::White);
	m_continueText.setPosition(sf::Vector2f{ 550.0f,800.0f });

	m_titleText.setFont(m_font);
	m_titleText.setString("Mimi");
	m_titleText.setCharacterSize(200);
	m_titleText.setFillColor(sf::Color::White);
	m_titleText.setPosition(sf::Vector2f{ 630.0f,400.0f });
}

void SplashScreen::setupSprite()
{
	if (!m_playertex.loadFromFile("ASSETS/IMAGES/Characters/player.png"))
	{
		std::cout << "error loading player texture" << std::endl;
	}
	m_player.setTexture(m_playertex,true);
	m_player.setScale(15, 15);
	m_player.setTextureRect(m_playerRect);
	m_player.setPosition(sf::Vector2f{ 900,650 });


	if (!m_backgroundTex.loadFromFile("ASSETS/IMAGES/Backgrounds/splashScreen.png"))
	{
		std::cout << "error loading background texture" << std::endl;
	}
	m_background.setTexture(m_backgroundTex, true);
	m_background.setScale(2, 2);
	m_background.setPosition(sf::Vector2f{ 0, 0 });
}
