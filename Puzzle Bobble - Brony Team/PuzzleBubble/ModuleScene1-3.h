#ifndef __MODULESCENE1TO3_H__
#define __MODULESCENE1TO3_H__

#include "../Module.h"
#include "../Animation.h"
#include "ModuleAudio.h"

#define NUM_BUBBLES_1 5

struct SDL_Texture;

class ModuleScene1to3 : public Module {
public:

	ModuleScene1to3();
	~ModuleScene1to3();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void PopBubbles();

public:
	SDL_Texture* background_graphics = nullptr;
	SDL_Texture* foreground_graphics = nullptr;
	SDL_Texture* game_sprites_graphics = nullptr;
	SDL_Rect bubbles[NUM_BUBBLES_1];
	SDL_Rect foreground;
	SDL_Rect background;
	SDL_Rect limit_line;
	SDL_Rect level_info;
	int bubble_board[12][8];
	int prev_bb[12][8];
	bool to_erase;
	bool playonce;

	Mix_Chunk* sfx05 = nullptr;

};

#endif 