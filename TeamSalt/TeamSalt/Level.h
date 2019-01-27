#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Ground.h"
#include <iostream>

class Level
{
public:
	Level();
	~Level();

	void initialise(sf::Font &t_font);
	void render(sf::RenderWindow &t_window);
	void update(sf::Time dt);

	Ground m_groundTiles[MAX_TILES];

private:
	void setupSprite();
	void setupText();
	void setupTiles();


	sf::Sprite m_background;
	sf::Texture m_texture;

	sf::Vector2f m_pos;
};