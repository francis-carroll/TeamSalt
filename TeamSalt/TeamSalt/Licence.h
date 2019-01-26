#include "SFML/Graphics.hpp"

class LicenceScreen
{
public:
	LicenceScreen();
	~LicenceScreen();

	void draw(sf::RenderWindow &t_window);
	void update(sf::Time dt);
private:
	sf::Sprite m_sfmlLogo;
	sf::Texture m_logoTex;

};


