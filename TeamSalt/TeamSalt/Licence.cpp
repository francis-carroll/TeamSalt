#include "Licence.h"
#include "Game.h"

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
	t_window.draw(m_sfmlText);

	t_window.display();
}

void LicenceScreen::update(sf::Time dt)
{
	m_animationTimer += dt;

	if (m_animationTimer.asSeconds() > timeBudget && m_animationState == AnimationState::Appear)
	{
		m_animationState = AnimationState::None;

		distance = m_sfmlLogo.getPosition().y - (SCREEN_HEIGHT / 3.0);
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
		if (m_sfmlText.getFillColor().a < 255)
		{
			m_sfmlText.setFillColor(m_sfmlText.getFillColor() + sf::Color(0.0f, 0.0f, 0.0f, 3.0f));
		}

		if (m_animationTimer.asSeconds() > (timeBudget / 2.0))
		{
			m_sfmlLogo.setPosition(m_sfmlLogo.getPosition().x + incrementation, m_sfmlLogo.getPosition().y);

			if (m_sfmlLogo.getRotation() < 360)
			{
				m_sfmlLogo.setRotation(m_sfmlLogo.getRotation() + incrementation);
			}
		}
	}

	if (m_sfmlLogo.getPosition().x >= 1600)
	{
		if (m_sfmlText.getFillColor().a > 0)
		{
			m_sfmlText.setFillColor(m_sfmlText.getFillColor() - sf::Color(0.0f, 0.0f, 0.0f, 3.0f));
		}
		if (m_sfmlText.getFillColor().a <= 0)
		{
			Game::m_currentMode = GameMode::Author;
		}
	}
}

void LicenceScreen::setupText()
{
	m_sfmlText.setFont(m_font);
	m_sfmlText.setCharacterSize(200);
	m_sfmlText.setString("Made using SFML");
	m_sfmlText.setPosition(150.0f, 650.0f);
	m_sfmlText.setFillColor(sf::Color(255.0f,255.0f,255.0f,0.0f));
}

void LicenceScreen::setupSprite()
{
	if (!m_logoTex.loadFromFile("resources/images/logoSFML.png"))
	{
		std::cout << "error loading sfml logo" << std::endl;
	}
	m_sfmlLogo.setTexture(m_logoTex);
	m_sfmlLogo.setOrigin(m_sfmlLogo.getGlobalBounds().width / 2, m_sfmlLogo.getGlobalBounds().height / 2);
	m_sfmlLogo.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT + m_sfmlLogo.getGlobalBounds().width);
	m_sfmlLogo.setScale(2.5, 2.5);

	distance =  m_sfmlLogo.getPosition().y - SCREEN_WIDTH / 1.5;
	numberOfUpdates = distance / incrementation;
	timeBudget = numberOfUpdates / 60.0f;
}
