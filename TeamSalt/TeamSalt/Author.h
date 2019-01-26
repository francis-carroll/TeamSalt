#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

class AuthorScreen
{
public:
	AuthorScreen();
	~AuthorScreen();

	void initialise(sf::Font &t_font);
	void draw(sf::RenderWindow &t_window);
	void update(sf::Time dt);
private:
	void setupText();
	void setupSprite();
	void setupMusic();

	sf::Sprite m_logo;
	sf::Texture m_logoTex;
	sf::Text m_madeBytext;
	sf::Font m_font;
};
