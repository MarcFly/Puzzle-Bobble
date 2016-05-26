#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "ModuleEnemies.h"
#include "PuzzleBubble/ModuleAudio.h"

#define NUM_ARROW_SPRITES 130

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
		ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	void PlayerShoot();
	void StartingSequence();

public:
	double player_angle;

	SDL_Texture* greenbub_graphics = nullptr;
	SDL_Texture* sign_graphics = nullptr;
	SDL_Texture* graphics = nullptr;
	SDL_Rect round_greenbub;
	SDL_Rect greenbub_num;
	SDL_Rect round_sign;
	SDL_Rect tube;
	SDL_Rect b_machine[12];
	SDL_Rect s_machine[2];
	SDL_Rect arrow[64];
	SDL_Rect crank[8];
	SDL_Rect bub_wheel[9];
	SDL_Point arrow_center;
	SDL_Rect BluBub;
	SDL_Rect RedBub;
	SDL_Rect GreenBub;
	SDL_Rect YelBub;
	SDL_Rect BlkBub;
	SDL_Rect GreyBub;
	SDL_Rect OraBub;
	SDL_Rect PplBub;
	int arrow_pos;
	int bmachine_pos;
	int smachine_pos;
	int crank_pos;
	int bubwheel_pos;
	int change_sprite;
	int board_copy[96];
	int rnd;
	int rnd_aux;

	uint timer_secs;
	bool ready_playonce;

	Mix_Chunk* sfx08 = nullptr;

	uint score = 0;
	char score_text[10];
	char round_text[15];
	char credits_text[15];
	int font_score = -1;
	int timer;

	int shots;

	int timer_shot;

	bool show_credits;
	int last_time_credits;

	//audio
	Mix_Chunk* sfx01 = nullptr;
	Mix_Chunk* sfx11 = nullptr;

	iPoint position;

};

#endif