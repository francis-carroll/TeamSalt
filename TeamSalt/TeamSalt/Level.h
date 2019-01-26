#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class Level
{
public:
	Level();
	~Level();

	void initialise(sf::Font &t_font);
	void render(sf::RenderWindow &t_window);
	void update(sf::Time dt);
private:
	void setupSprite();
	void setupText();

	sf::Sprite m_sky;
	sf::Texture m_skyTex;
	sf::Sprite m_bgLayer1;
	sf::Texture m_bgLayer1Tex;
	sf::Sprite m_bgLayer2;
	sf::Texture m_bgLayer2Tex;
	sf::Sprite m_bgLayer3;
	sf::Texture m_bgLayer3Tex;

	sf::Sprite m_background;
	sf::Texture m_texture;

	sf::Vector2f m_pos;
};