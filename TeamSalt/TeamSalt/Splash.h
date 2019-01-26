
#include "SFML/Graphics.hpp"

class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void draw(sf::RenderWindow &t_window);
	void update(sf::Time dt);
private:
	sf::Sprite m_background;
	sf::Sprite m_player;
	sf::Font m_font;
	sf::Text m_continueText;
};
