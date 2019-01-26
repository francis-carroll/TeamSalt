#include "Author.h"
#include "Game.h"

AuthorScreen::AuthorScreen()
{
}

AuthorScreen::~AuthorScreen()
{
}

void AuthorScreen::initialise(sf::Font & t_font)
{
	m_font = t_font;
	setupText();
	setupSprite();
	setupMusic();
}

void AuthorScreen::draw(sf::RenderWindow & t_window)
{
	t_window.clear(sf::Color::Black);
	t_window.draw(m_logo);
	t_window.draw(m_madeBytext);
	t_window.display();
}

void AuthorScreen::update(sf::Time dt)
{
	m_timer += dt;
	if (m_timer.asSeconds() >= 1 && m_timer.asSeconds() < 3)
	{
		m_logo.setColor(m_logo.getColor() + sf::Color{ 0,0,0,5 });
		m_madeBytext.setFillColor(m_madeBytext.getFillColor() + sf::Color{ 0,0,0,5 });
	}
	if (m_timer.asSeconds() >= 3 && m_timer.asSeconds() < 4)
	{
		m_logo.setColor(m_logo.getColor() - sf::Color{ 0,0,0,5 });
		m_madeBytext.setFillColor(m_madeBytext.getFillColor() - sf::Color{ 0,0,0,5 });
	}

	if (m_timer.asSeconds() > 4)
	{
		Game::m_currentMode = GameMode::Splash;
	}
}

void AuthorScreen::setupText()
{
	m_madeBytext.setFont(m_font);
	m_madeBytext.setFillColor(sf::Color::White);
	m_madeBytext.setFillColor(m_madeBytext.getFillColor() - sf::Color{0,0,0,255});
	m_madeBytext.setPosition(sf::Vector2f{ 460.0f,800.0f });
	m_madeBytext.setCharacterSize(100);
	m_madeBytext.setString("Made By Team Salt");

}

void AuthorScreen::setupSprite()
{
	if (!m_logoTex.loadFromFile("resources/images/logo.png"))
	{
		std::cout << "Error loading logo image" << std::endl;
	}
	m_logo.setTexture(m_logoTex);
	m_logo.setScale(2, 2);
	m_logo.setColor(m_logo.getColor() - sf::Color{ 0,0,0,255 });
	m_logo.setPosition(sf::Vector2f{ 630.0f,300.0f });

}

void AuthorScreen::setupMusic()
{
}
