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

static const int MAX_TILES = 100;

#endif