#ifndef LICENCE
#define LICENCE

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class LicenceScreen
{
public:
	LicenceScreen();
	~LicenceScreen();

	void initialise(sf::Font &t_font);
	void render(sf::RenderWindow &t_window);
	void update(sf::Time dt);
private:
	void setupText();
	void setupSprite();

	AnimationState m_animationState{ AnimationState::Appear };
	sf::Time m_animationTimer;
	int numberOfUpdates{ 0 };
	float timeBudget{ 0.0f };
	float distance{ 0.0f };
	const float incrementation{ 10.0f };

	sf::Sprite m_sfmlLogo;
	sf::Texture m_logoTex;
	sf::Text m_sfmlText;
	sf::Font m_font;
};
#endif
