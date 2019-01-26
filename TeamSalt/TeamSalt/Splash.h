
#include "SFML/Graphics.hpp"
class SplashScreen
{
public:
	SplashScreen();
	~SplashScreen();

	void initialise(sf::Font &t_font);
	void draw(sf::RenderWindow &t_window);
	void update(sf::Time dt);
private:
	void setupText();
	void setupSprite();

	sf::Sprite m_background;
	sf::Sprite m_player;
	sf::Font m_font;
	sf::Text m_continueText;
};
