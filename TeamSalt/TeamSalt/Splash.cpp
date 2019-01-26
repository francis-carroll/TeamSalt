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
}

void SplashScreen::draw(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(m_continueText);
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
}
