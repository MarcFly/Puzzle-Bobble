#ifndef __MODULESCENE1TO3_H__
#define __MODULESCENE1TO3_H__

#include "../Module.h"
#include "../Animation.h"
#include "ModuleAudio.h"

#define NUM_BUBBLES_1 5
#define FALLING_CEILING_SPEED 15;

struct SDL_Texture;

class ModuleScene1to3 : public Module {
public:

	ModuleScene1to3();
	~ModuleScene1to3();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void FallCeiling();

public:
	SDL_Texture* background_graphics = nullptr;
	SDL_Texture* foreground_graphics = nullptr;
	SDL_Texture* game_sprites_graphics = nullptr;
	SDL_Texture* falling_graphics = nullptr;
	SDL_Rect falling_ceiling;
	SDL_Rect bubbles[NUM_BUBBLES_1];
	SDL_Rect ceiling;
	SDL_Rect wall;
	SDL_Rect background;
	SDL_Rect top_background;
	SDL_Rect limit_line;
	SDL_Rect level_info;
	int bubble_board[12][8];
	int prev_bb[12][8];
	bool to_erase;
	bool playonce;
	bool play_sfx13_once;
	Collider* col_ceiling;
	int deadline_pos;
	uint last_time;

	uint BUBBLE_OFFSET_X_ODD = 71;
	uint BUBBLE_OFFSET_Y = 8;
	uint BUBBLE_OFFSET_X_PAIR = 64;

	uint death_timer;
	bool death_once;

	uint win_timer;
	bool win_once;

	bool shake_timer_once;
	uint shake_timer;

	bool is_gameover;

	bool shake;

	Mix_Chunk* sfx13 = nullptr;
	Mix_Chunk* sfx09 = nullptr;
	Mix_Chunk* sfx07 = nullptr;

};

#endif 