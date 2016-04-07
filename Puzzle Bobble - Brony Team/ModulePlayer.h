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
	int player_angle = 0;
	int current_arrow = 65;

	SDL_Texture* graphics = nullptr;
	SDL_Rect arrow[NUM_ARROW_SPRITES];
	
	iPoint position;

};

#endif