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
	double player_angle = 90;

	SDL_Texture* graphics = nullptr;
	SDL_Rect arrow;
	SDL_Point arrow_center;

	iPoint position;

};

#endif