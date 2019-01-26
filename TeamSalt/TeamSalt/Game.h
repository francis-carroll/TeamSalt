#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Licence.h"
#include "Splash.h"
#include "Author.h"
#include "LevelLoader.h"
#include "Player.h"

// pete is cool 

class Game
{
public:
	Game();
	~Game();
	void run();
	static GameMode m_currentMode;

private:
	void setup();
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();

	LevelData m_level;

	player m_player;

	//instances of each screens
	LicenceScreen m_licenceScreen;
	SplashScreen m_splashScreen;
	AuthorScreen m_authorScreen;

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_font;
	bool m_exitGame;
};

#endif // !GAME
