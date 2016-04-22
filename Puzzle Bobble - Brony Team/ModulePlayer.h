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
	SDL_Rect tube;
	SDL_Rect b_machine[12];
	SDL_Rect s_machine[2];
	SDL_Rect arrow[64];
	SDL_Rect crank[8];
	SDL_Point arrow_center;
	int arrow_pos;
	int bmachine_pos;
	int smachine_pos;
	int crank_pos;

	iPoint position;

};

#endif