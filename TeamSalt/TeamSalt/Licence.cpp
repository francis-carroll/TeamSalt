#include "Licence.h"

LicenceScreen::LicenceScreen()
{
}

LicenceScreen::~LicenceScreen()
{
}

void LicenceScreen::initialise(sf::Font & t_font)
{
	m_font = t_font;
	setupText();
	setupSprite();
}

void LicenceScreen::render(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);

	if (m_animationState != AnimationState::Done)
	{
		t_window.draw(m_sfmlLogo);
	}

	t_window.display();
}

void LicenceScreen::update(sf::Time dt)
{
	m_animationTimer += dt;

	if (m_animationTimer.asSeconds() > timeBudget && m_animationState == AnimationState::Appear)
	{
		m_animationState = AnimationState::None;

		distance = m_sfmlLogo.getPosition().y - (SCREEN_HEIGHT / 4.0);
		numberOfUpdates = distance / incrementation;
		timeBudget = numberOfUpdates / 60.0f;

		timeBudget = timeBudget * 2;

		m_animationTimer = sf::Time::Zero;
	}
	if (m_animationTimer.asSeconds() > timeBudget && m_animationState == AnimationState::None)
	{
		m_animationState = AnimationState::Disappear;

		distance = (SCREEN_WIDTH + m_sfmlLogo.getGlobalBounds().width * 2.0) - m_sfmlLogo.getPosition().x;
		numberOfUpdates = distance / incrementation;
		timeBudget = numberOfUpdates / 60.0f;

		timeBudget = timeBudget * 2;

		m_animationTimer = sf::Time::Zero;
	}
	if (m_animationTimer.asSeconds() > timeBudget && m_animationState == AnimationState::Disappear)
	{
		m_animationState = AnimationState::Done;
	}

	if (m_animationTimer.asSeconds() < timeBudget && m_animationState == AnimationState::Appear)
	{
		m_sfmlLogo.setPosition(m_sfmlLogo.getPosition().x, m_sfmlLogo.getPosition().y - incrementation);

		if (m_sfmlLogo.getRotation() < 45)
		{
			m_sfmlLogo.setRotation(m_sfmlLogo.getRotation() + 1);
		}
	}

	if (m_animationTimer.asSeconds() < timeBudget && m_animationState == AnimationState::None)
	{
		if (m_animationTimer.asSeconds() > (timeBudget / 2.0))
		{
			m_sfmlLogo.setPosition(m_sfmlLogo.getPosition().x, m_sfmlLogo.getPosition().y - incrementation);

			if (m_sfmlLogo.getRotation() > 0)
			{
				m_sfmlLogo.setRotation(m_sfmlLogo.getRotation() - 1);
			}
		}
	}

	if (m_animationTimer.asSeconds() < timeBudget && m_animationState == AnimationState::Disappear)
	{
		if (m_animationTimer.asSeconds() > (timeBudget / 2.0))
		{
			m_sfmlLogo.setPosition(m_sfmlLogo.getPosition().x + incrementation, m_sfmlLogo.getPosition().y);

			if (m_sfmlLogo.getRotation() < 360)
			{
				m_sfmlLogo.setRotation(m_sfmlLogo.getRotation() + incrementation);
			}
		}
	}
}

void LicenceScreen::setupText()
{
}

void LicenceScreen::setupSprite()
{
	/*if (!m_logoTex.loadFromFile("sfmlLogo.png"))
	{

	}*/
}
