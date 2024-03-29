#ifndef SPLASH
#define SPLASH

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Controller.h"
#include <iostream>

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
	void setupMusic();

	sf::Sprite m_background;
	sf::Texture m_backgroundTex;
	sf::Sprite m_player;
	sf::Texture m_playertex;
	sf::IntRect m_playerRect;
	int m_timer;
	sf::Font m_font;
	sf::Text m_continueText;
	sf::Text m_titleText;
	sf::SoundBuffer m_titleMusicBuffer;
	sf::Sound m_titleMusic;
	Xbox360Controller m_controller;
};

#endif