#ifndef __MODULESCENE1TO3_H__
#define __MODULESCENE1TO3_H__

#include "../Module.h"
#include "../Animation.h"

#define NUM_BUBBLES_1 5

struct SDL_Texture;

class ModuleScene1to3 : public Module {
public:

	ModuleScene1to3();
	~ModuleScene1to3();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	SDL_Texture* background_graphics = nullptr;
	SDL_Texture* foreground_graphics = nullptr;
	SDL_Texture* game_sprites_graphics = nullptr;
	SDL_Rect bubbles[NUM_BUBBLES_1];
	SDL_Rect foreground;
	SDL_Rect background;
	int bubble_board[12][8];

};

#endif 