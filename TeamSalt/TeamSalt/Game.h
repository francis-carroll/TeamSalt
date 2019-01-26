#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Licence.h"
#include "Splash.h"

class Game
{
public:
	Game();
	~Game();
	void run();
	static GameMode m_currentMode;

private:

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	//instances of each screens
	Licence m_licenceScreen;
	Splash m_splashScreen;

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_font;
	bool m_exitGame;
};

#endif // !GAME
