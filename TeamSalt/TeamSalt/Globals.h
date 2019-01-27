#ifndef GLOBALS
#define GLOBALS

enum class AnimationState
{
	None,
	Appear,
	Disappear,
	Done
};

enum class GameMode
{
	Licence,
	Splash,
	Author,
	GamePlay,
	Level1,
	Pause,
	Credits,
	LoadLevel,
	MainMenu
};

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 1200;

const sf::Vector2f GRAVITY{ 0.0f, 9.8f };

static const int MAX_TILES = 100;

#endif