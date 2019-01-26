#include "Splash.h"

SplashScreen::SplashScreen()
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
	t_window.draw(m_continueText);
	t_window.draw(m_player);
	t_window.display();
}

void SplashScreen::update(sf::Time dt)
{
}

void SplashScreen::setupText()
{
	m_continueText.setFont(m_font);
	m_continueText.setString("Press Space to Continue");
	m_continueText.setCharacterSize(50);
	m_continueText.setFillColor(sf::Color::White);
	m_continueText.setPosition(sf::Vector2f{ 500.0f,800.0f });
}

void SplashScreen::setupSprite()
{
	if (!m_playertex.loadFromFile("resources/images/characters/player.png"))
	{
		std::cout << "error loading player texture" << std::endl;
	}
	m_player.setTexture(m_playertex,true);
	m_player.setScale(15, 15);
	m_player.setTextureRect(sf::IntRect{ 0,0,25,33 });
	m_player.setPosition(sf::Vector2f{ 100,100 });


	if (!m_backgroundTex.loadFromFile("resources/images/backgrounds/splashScreen.png"))
	{
		std::cout << "error loading player texture" << std::endl;
	}
	m_background.setTexture(m_backgroundTex);
	m_background.setPosition(sf::Vector2f{ 0, 0 });
}
