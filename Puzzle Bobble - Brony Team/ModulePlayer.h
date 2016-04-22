#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

#define NUM_ARROW_SPRITES 130

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();

public:
	double player_angle;

	SDL_Texture* graphics = nullptr;
	SDL_Texture* game_sprites_graphics;
	SDL_Rect bub_wheel[8];
	SDL_Rect bubblun_rotate[8];
	SDL_Rect tube;
	SDL_Rect b_machine[12];
<<<<<<< HEAD
	SDL_Rect a_machine[2];
	SDL_Rect arrow[64];
	SDL_Point arrow_center;
	uint arrow_pos;
	uint machine_pos;
	bool amach_blit_check = false;
	uint bub_pos;
	uint bub_repos_x[8];
=======
	SDL_Rect s_machine[2];
	SDL_Rect arrow[64];
	SDL_Point arrow_center;
	int arrow_pos;
	int bmachine_pos;
	uint smachine_pos;
>>>>>>> origin/master

	iPoint position;

};

#endif