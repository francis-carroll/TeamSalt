#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class Ground
{
public:
	Ground();
	~Ground();

	void initialise(sf::Font &t_font);
	void render(sf::RenderWindow &t_window);
	void update(sf::Time dt);
	void setPosition(sf::Vector2f t_pos);
	sf::Vector2f getPosition();
private:
	void setupSprite();

	sf::Sprite m_sprite;
	sf::Texture m_spriteTex;
	sf::Vector2f m_pos;
};