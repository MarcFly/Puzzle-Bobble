#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "Globals.h"
#include "Application.h"
#include "Bobbles.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "PuzzleBubble/ModuleParticles.h"
#include "PuzzleBubble/ModuleAudio.h"
#include "PuzzleBubble/ModuleScene1-3.h"
#include "PuzzleBubble/ModuleScene4-6.h"
#include "PuzzleBubble/ModuleSceneMainMenu.h"
#include "PuzzleBubble/ModuleFadeToBlack.h"
#include "PuzzleBubble/ModuleFonts.h"
#include "stdio.h"


#define ANGLE_INCREMENT 85.f/62.f

int ply_score = 0;

ModulePlayer::ModulePlayer()
{
	srand(time(NULL));

	// bubbles

	BluBub.x = 18;
	BluBub.y = 559;
	BluBub.w = 16;
	BluBub.h = 16;
				
	RedBub.x = 18;
	RedBub.y = 607;
	RedBub.w = 16;
	RedBub.h = 16;
				
	GreenBub.x = 266;
	GreenBub.y = 559;
	GreenBub.w = 16;
	GreenBub.h = 16;
				
	YelBub.x = 18;
	YelBub.y = 631;
	YelBub.w = 16;
	YelBub.h = 16;
				
	BlkBub.x = 266;
	BlkBub.y = 583;
	BlkBub.w = 16;
	BlkBub.h = 16;
				
	GreyBub.x = 18;
	GreyBub.y = 583;
	GreyBub.w = 16;
	GreyBub.h = 16;
				
	OraBub.x = 266;
	OraBub.y = 607;
	OraBub.w = 16;
	OraBub.h = 16;
				
	PplBub.x = 266;
	PplBub.y = 631;
	PplBub.w = 16;
	PplBub.h = 16;

	// tube 

	tube.x = 556;
	tube.y = 498;
	tube.w = 13;
	tube.h = 11;

	// bag

	bag[0].x = 294;
	bag[0].y = 489;
	bag[0].w = 56;
	bag[0].h = 24;

	bag[1].x = 351;
	bag[1].y = 490;
	bag[1].w = 40;
	bag[1].h = 23;

	// small machine

	s_machine[0].x = 522;
	s_machine[0].y = 515;
	s_machine[0].w = 34;
	s_machine[0].h = 16;

	s_machine[1].x = 522;
	s_machine[1].y = 532;
	s_machine[1].w = 34;
	s_machine[1].h = 16;

	// big machine

	b_machine[0].x = 66;
	b_machine[0].y = 464;
	b_machine[0].w = 56;
	b_machine[0].h = 24;

	b_machine[1].x = 123;
	b_machine[1].y = 464;
	b_machine[1].w = 56;
	b_machine[1].h = 24;

	b_machine[2].x = 180;
	b_machine[2].y = 464;
	b_machine[2].w = 56;
	b_machine[2].h = 24;

	b_machine[3].x = 237;
	b_machine[3].y = 464;
	b_machine[3].w = 56;
	b_machine[3].h = 24;

	b_machine[4].x = 294;
	b_machine[4].y = 464;
	b_machine[4].w = 56;
	b_machine[4].h = 24;

	b_machine[5].x = 351;
	b_machine[5].y = 464;
	b_machine[5].w = 56;
	b_machine[5].h = 24;

	b_machine[6].x = 408;
	b_machine[6].y = 464;
	b_machine[6].w = 56;
	b_machine[6].h = 24;

	b_machine[7].x = 465;
	b_machine[7].y = 464;
	b_machine[7].w = 56;
	b_machine[7].h = 24;

	b_machine[8].x = 66;
	b_machine[8].y = 489;
	b_machine[8].w = 56;
	b_machine[8].h = 24;

	b_machine[9].x = 123;
	b_machine[9].y = 489;
	b_machine[9].w = 56;
	b_machine[9].h = 24;

	b_machine[10].x = 180;
	b_machine[10].y = 489;
	b_machine[10].w = 56;
	b_machine[10].h = 24;

	b_machine[11].x = 237;
	b_machine[11].y = 489;
	b_machine[11].w = 56;
	b_machine[11].h = 24;

	// crank

	crank[0].x = 522;
	crank[0].y = 464;
	crank[0].w = 16;
	crank[0].h = 16;

	crank[1].x = 539;
	crank[1].y = 464;
	crank[1].w = 16;
	crank[1].h = 16;

	crank[2].x = 556;
	crank[2].y = 464;
	crank[2].w = 16;
	crank[2].h = 16;

	crank[3].x = 522;
	crank[3].y = 481;
	crank[3].w = 16;
	crank[3].h = 16;

	crank[4].x = 539;
	crank[4].y = 481;
	crank[4].w = 16;
	crank[4].h = 16;

	crank[5].x = 556;
	crank[5].y = 481;
	crank[5].w = 16;
	crank[5].h = 16;

	crank[6].x = 522;
	crank[6].y = 498;
	crank[6].w = 16;
	crank[6].h = 16;

	crank[7].x = 539;
	crank[7].y = 498;
	crank[7].w = 16;
	crank[7].h = 16;

	// BUB wheel

	bub_wheel[0].x = 66;
	bub_wheel[0].y = 539;
	bub_wheel[0].w = 26;
	bub_wheel[0].h = 19;

	bub_wheel[1].x = 93;
	bub_wheel[1].y = 539;
	bub_wheel[1].w = 26;
	bub_wheel[1].h = 19;

	bub_wheel[2].x = 120;
	bub_wheel[2].y = 539;
	bub_wheel[2].w = 26;
	bub_wheel[2].h = 19;

	bub_wheel[3].x = 147;
	bub_wheel[3].y = 539;
	bub_wheel[3].w = 26;
	bub_wheel[3].h = 19;

	bub_wheel[4].x = 174;
	bub_wheel[4].y = 539;
	bub_wheel[4].w = 26;
	bub_wheel[4].h = 19;

	bub_wheel[5].x = 201;
	bub_wheel[5].y = 539;
	bub_wheel[5].w = 26;
	bub_wheel[5].h = 19;

	bub_wheel[6].x = 228;
	bub_wheel[6].y = 539;
	bub_wheel[6].w = 26;
	bub_wheel[6].h = 19;

	bub_wheel[7].x = 255;
	bub_wheel[7].y = 539;
	bub_wheel[7].w = 26;
	bub_wheel[7].h = 19;

	bub_wheel[8].x = 281;
	bub_wheel[8].y = 539;
	bub_wheel[8].w = 26;
	bub_wheel[8].h = 19;

	bub_wheel[9].x = 309;
	bub_wheel[9].y = 539;
	bub_wheel[9].w = 26;
	bub_wheel[9].h = 19;

	bub_wheel[10].x = 336;
	bub_wheel[10].y = 539;
	bub_wheel[10].w = 26;
	bub_wheel[10].h = 19;

	bub_wheel[11].x = 363;
	bub_wheel[11].y = 539;
	bub_wheel[11].w = 26;
	bub_wheel[11].h = 19;

	bub_wheel[12].x = 390;
	bub_wheel[12].y = 539;
	bub_wheel[12].w = 26;
	bub_wheel[12].h = 19;

	bub_wheel[13].x = 417;
	bub_wheel[13].y = 539;
	bub_wheel[13].w = 26;
	bub_wheel[13].h = 19;

	//BUB ball

	bub_ball[0].x = 0;
	bub_ball[0].y = 655;
	bub_ball[0].w = 26;
	bub_ball[0].h = 19;

	bub_ball[1].x = 27;
	bub_ball[1].y = 655;
	bub_ball[1].w = 26;
	bub_ball[1].h = 19;

	bub_ball[2].x = 54;
	bub_ball[2].y = 655;
	bub_ball[2].w = 26;
	bub_ball[2].h = 19;

	bub_ball[3].x = 81;
	bub_ball[3].y = 655;
	bub_ball[3].w = 26;
	bub_ball[3].h = 19;

	bub_ball[4].x = 108;
	bub_ball[4].y = 655;
	bub_ball[4].w = 26;
	bub_ball[4].h = 19;

	bub_ball[5].x = 135;
	bub_ball[5].y = 655;
	bub_ball[5].w = 26;
	bub_ball[5].h = 19;

	bub_ball[6].x = 162;
	bub_ball[6].y = 655;
	bub_ball[6].w = 26;
	bub_ball[6].h = 19;

	bub_ball[7].x = 189;
	bub_ball[7].y = 655;
	bub_ball[7].w = 26;
	bub_ball[7].h = 19;

	bub_ball[8].x = 216;
	bub_ball[8].y = 655;
	bub_ball[8].w = 26;
	bub_ball[8].h = 19;

	bub_ball[9].x = 243;
	bub_ball[9].y = 655;
	bub_ball[9].w = 26;
	bub_ball[9].h = 19;

	bub_ball[10].x = 270;
	bub_ball[10].y = 655;
	bub_ball[10].w = 26;
	bub_ball[10].h = 19;

	bub_ball[11].x = 297;
	bub_ball[11].y = 655;
	bub_ball[11].w = 26;
	bub_ball[11].h = 19;


	// messages

	messages[0].x = 1;
	messages[0].y = 675;
	messages[0].w = 32;
	messages[0].h = 28;

	messages[1].x = 34;
	messages[1].y = 675;
	messages[1].w = 32;
	messages[1].h = 28;

	messages[2].x = 67;
	messages[2].y = 675;
	messages[2].w = 32;
	messages[2].h = 28;

	messages[3].x = 100;
	messages[3].y = 675;
	messages[3].w = 32;
	messages[3].h = 28;

	messages[4].x = 133;
	messages[4].y = 675;
	messages[4].w = 32;
	messages[4].h = 28;

	messages[5].x = 166;
	messages[5].y = 675;
	messages[5].w = 32;
	messages[5].h = 28;

	//all arrow animation frames

	position.x = 120;
	position.y = 163;

	arrow[0].x = 2;
	arrow[0].y = 2;
	arrow[0].w = 62;
	arrow[0].h = 64;

	arrow[1].x = 66;
	arrow[1].y = 2;
	arrow[1].w = 62;
	arrow[1].h = 64;

	arrow[2].x = 130;
	arrow[2].y = 2;
	arrow[2].w = 62;
	arrow[2].h = 64;

	arrow[3].x = 194;
	arrow[3].y = 2;
	arrow[3].w = 62;
	arrow[3].h = 64;

	arrow[4].x = 258;
	arrow[4].y = 2;
	arrow[4].w = 62;
	arrow[4].h = 64;

	arrow[5].x = 322;
	arrow[5].y = 2;
	arrow[5].w = 62;
	arrow[5].h = 64;

	arrow[6].x = 386;
	arrow[6].y = 2;
	arrow[6].w = 62;
	arrow[6].h = 64;

	arrow[7].x = 450;
	arrow[7].y = 2;
	arrow[7].w = 62;
	arrow[7].h = 64;

	arrow[8].x = 514;
	arrow[8].y = 2;
	arrow[8].w = 62;
	arrow[8].h = 64;

	arrow[9].x = 2;
	arrow[9].y = 68;
	arrow[9].w = 62;
	arrow[9].h = 64;

	arrow[10].x = 66;
	arrow[10].y = 68;
	arrow[10].w = 62;
	arrow[10].h = 64;

	arrow[11].x = 130;
	arrow[11].y = 68;
	arrow[11].w = 62;
	arrow[11].h = 64;

	arrow[12].x = 194;
	arrow[12].y = 68;
	arrow[12].w = 62;
	arrow[12].h = 64;

	arrow[13].x = 258;
	arrow[13].y = 68;
	arrow[13].w = 62;
	arrow[13].h = 64;

	arrow[14].x = 322;
	arrow[14].y = 68;
	arrow[14].w = 62;
	arrow[14].h = 64;

	arrow[15].x = 386;
	arrow[15].y = 68;
	arrow[15].w = 62;
	arrow[15].h = 64;

	arrow[16].x = 450;
	arrow[16].y = 68;
	arrow[16].w = 62;
	arrow[16].h = 64;

	arrow[17].x = 514;
	arrow[17].y = 68;
	arrow[17].w = 62;
	arrow[17].h = 64;

	arrow[18].x = 2;
	arrow[18].y = 134;
	arrow[18].w = 62;
	arrow[18].h = 64;

	arrow[19].x = 66;
	arrow[19].y = 134;
	arrow[19].w = 62;
	arrow[19].h = 64;

	arrow[20].x = 130;
	arrow[20].y = 134;
	arrow[20].w = 62;
	arrow[20].h = 64;

	arrow[21].x = 194;
	arrow[21].y = 134;
	arrow[21].w = 62;
	arrow[21].h = 64;

	arrow[22].x = 258;
	arrow[22].y = 134;
	arrow[22].w = 62;
	arrow[22].h = 64;

	arrow[23].x = 322;
	arrow[23].y = 134;
	arrow[23].w = 62;
	arrow[23].h = 64;

	arrow[24].x = 386;
	arrow[24].y = 134;
	arrow[24].w = 62;
	arrow[24].h = 64;

	arrow[25].x = 450;
	arrow[25].y = 134;
	arrow[25].w = 62;
	arrow[25].h = 64;

	arrow[26].x = 514;
	arrow[26].y = 134;
	arrow[26].w = 62;
	arrow[26].h = 64;

	arrow[27].x = 2;
	arrow[27].y = 200;
	arrow[27].w = 62;
	arrow[27].h = 64;

	arrow[28].x = 66;
	arrow[28].y = 200;
	arrow[28].w = 62;
	arrow[28].h = 64;

	arrow[29].x = 130;
	arrow[29].y = 200;
	arrow[29].w = 62;
	arrow[29].h = 64;

	arrow[30].x = 194;
	arrow[30].y = 200;
	arrow[30].w = 62;
	arrow[30].h = 64;

	arrow[31].x = 258;
	arrow[31].y = 200;
	arrow[31].w = 62;
	arrow[31].h = 64;

	arrow[32].x = 322;
	arrow[32].y = 200;
	arrow[32].w = 62;
	arrow[32].h = 64;

	arrow[33].x = 386;
	arrow[33].y = 200;
	arrow[33].w = 62;
	arrow[33].h = 64;

	arrow[34].x = 450;
	arrow[34].y = 200;
	arrow[34].w = 62;
	arrow[34].h = 64;

	arrow[35].x = 514;
	arrow[35].y = 200;
	arrow[35].w = 62;
	arrow[35].h = 64;

	arrow[36].x = 2;
	arrow[36].y = 266;
	arrow[36].w = 62;
	arrow[36].h = 64;

	arrow[37].x = 66;
	arrow[37].y = 266;
	arrow[37].w = 62;
	arrow[37].h = 64;

	arrow[38].x = 130;
	arrow[38].y = 266;
	arrow[38].w = 62;
	arrow[38].h = 64;

	arrow[39].x = 194;
	arrow[39].y = 266;
	arrow[39].w = 62;
	arrow[39].h = 64;

	arrow[40].x = 258;
	arrow[40].y = 266;
	arrow[40].w = 62;
	arrow[40].h = 64;

	arrow[41].x = 322;
	arrow[41].y = 266;
	arrow[41].w = 62;
	arrow[41].h = 64;

	arrow[42].x = 386;
	arrow[42].y = 266;
	arrow[42].w = 62;
	arrow[42].h = 64;

	arrow[43].x = 450;
	arrow[43].y = 266;
	arrow[43].w = 62;
	arrow[43].h = 64;

	arrow[44].x = 514;
	arrow[44].y = 266;
	arrow[44].w = 62;
	arrow[44].h = 64;

	arrow[45].x = 2;
	arrow[45].y = 332;
	arrow[45].w = 62;
	arrow[45].h = 64;

	arrow[46].x = 66;
	arrow[46].y = 332;
	arrow[46].w = 62;
	arrow[46].h = 64;

	arrow[47].x = 130;
	arrow[47].y = 332;
	arrow[47].w = 62;
	arrow[47].h = 64;

	arrow[48].x = 194;
	arrow[48].y = 332;
	arrow[48].w = 62;
	arrow[48].h = 64;

	arrow[49].x = 258;
	arrow[49].y = 332;
	arrow[49].w = 62;
	arrow[49].h = 64;

	arrow[50].x = 322;
	arrow[50].y = 332;
	arrow[50].w = 62;
	arrow[50].h = 64;

	arrow[51].x = 386;
	arrow[51].y = 332;
	arrow[51].w = 62;
	arrow[51].h = 64;

	arrow[52].x = 450;
	arrow[52].y = 332;
	arrow[52].w = 62;
	arrow[52].h = 64;

	arrow[53].x = 514;
	arrow[53].y = 332;
	arrow[53].w = 62;
	arrow[53].h = 64;

	arrow[54].x = 2;
	arrow[54].y = 398;
	arrow[54].w = 62;
	arrow[54].h = 64;

	arrow[55].x = 66;
	arrow[55].y = 398;
	arrow[55].w = 62;
	arrow[55].h = 64;

	arrow[56].x = 130;
	arrow[56].y = 398;
	arrow[56].w = 62;
	arrow[56].h = 64;

	arrow[57].x = 194;
	arrow[57].y = 398;
	arrow[57].w = 62;
	arrow[57].h = 64;

	arrow[58].x = 258;
	arrow[58].y = 398;
	arrow[58].w = 62;
	arrow[58].h = 64;

	arrow[59].x = 322;
	arrow[59].y = 398;
	arrow[59].w = 62;
	arrow[59].h = 64;

	arrow[60].x = 386;
	arrow[60].y = 398;
	arrow[60].w = 62;
	arrow[60].h = 64;

	arrow[61].x = 450;
	arrow[61].y = 398;
	arrow[61].w = 62;
	arrow[61].h = 64;

	arrow[62].x = 514;
	arrow[62].y = 398;
	arrow[62].w = 62;
	arrow[62].h = 64;

	arrow[63].x = 2;
	arrow[63].y = 464;
	arrow[63].w = 62;
	arrow[63].h = 64;

	//-----------

	round_sign.x = 0;
	round_sign.y = 0;
	round_sign.w = 128;
	round_sign.h = 48;

	round_greenbub.x = 4;
	round_greenbub.y = 44;
	round_greenbub.w = 86;
	round_greenbub.h = 16;

	greenbub_num.x = 72;
	greenbub_num.y = 9;
	greenbub_num.w = 14;
	greenbub_num.h = 16;

	score = ply_score;


	BUB_yawn.PushBack({ bub_wheel[8] });
	BUB_yawn.PushBack({ bub_wheel[9] });
	BUB_yawn.PushBack({ bub_wheel[12] });
	BUB_yawn.PushBack({ bub_wheel[13] });
	BUB_yawn.PushBack({ bub_wheel[12] });
	BUB_yawn.PushBack({ bub_wheel[13] });
	BUB_yawn.PushBack({ bub_wheel[12] });
	BUB_yawn.PushBack({ bub_wheel[10] });

	BUB_yawn.speed = 0.1f;


	Bub_shoot.PushBack({ bub_ball[7] });
	Bub_shoot.PushBack({ bub_ball[8] });
	Bub_shoot.PushBack({ bub_ball[9] });
	Bub_shoot.PushBack({ bub_ball[0] });
	Bub_shoot.PushBack({ bub_ball[4] });
	Bub_shoot.PushBack({ bub_ball[5] });
	Bub_shoot.PushBack({ bub_ball[6] });
	Bub_shoot.PushBack({ bub_ball[0] });
	Bub_shoot.PushBack({ bub_ball[0] });

	Bub_shoot.speed = 0.13f;

	Bub_hurry.PushBack({ bub_ball[10] });
	Bub_hurry.PushBack({ bub_ball[11] });
	Bub_hurry.PushBack({ bub_ball[10] });
	Bub_hurry.PushBack({ bub_ball[11] });

	Bub_hurry.speed = 0.1f;


	Bub_stand.PushBack({ bub_ball[0] });
	Bub_stand.PushBack({ bub_ball[1] });
	Bub_stand.PushBack({ bub_ball[2] });
	Bub_stand.PushBack({ bub_ball[3] });

	Bub_stand.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{
}

bool ModulePlayer::CleanUp() {
	LOG("\nPlayer CleanUP");
	//Mix_FreeChunk(sfx01);

	timer_shot = SDL_GetTicks();

	App->textures->Unload(graphics);
	App->textures->Unload(sign_graphics);
	App->textures->Unload(greenbub_graphics);

	ply_score = score;

	LOG("\nPlayer CleanUp exited successfully");
	return true;
}

bool ModulePlayer::Start()
{
	LOG("Player Start");
	App->input->Disable();
	srand(time(NULL));

	enable_once = false;
	anim_shoot = false;
	get_shoot = true;

	timer_secs = SDL_GetTicks();

	sfx08 = nullptr;
	sfx11 = nullptr;
	sfx08 = Mix_LoadWAV("Resources/Audio/SFX/SFX 08.wav");
	sfx11 = Mix_LoadWAV("Resources/Audio/SFX/SFX 11.wav");
	
	Mix_PlayChannel(-1, sfx11, 0);

	shots = 0;

	show_credits = true;
	last_time_credits = SDL_GetTicks();

	LOG("Loading player textures");
	bool ret = true;

	arrow_center.x = 50;
	arrow_center.y = 128;

	arrow_pos = 0;
	bmachine_pos = 0;
	smachine_pos = 0;
	crank_pos = 0;
	bubwheel_pos = 0;
	change_sprite = 0;

	player_angle = 90;

	graphics = App->textures->Load("Resources/Sprites/Player sprites.png");
	sign_graphics = App->textures->Load("Resources/Sprites/round_sign.png");
	greenbub_graphics = App->textures->Load("Resources/Sprites/GreenBubFont.png");
	font_score = App->fonts->Load("Resources/Sprites/stdWhiteFontCLEAN.png", " !@,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);

	rnd = 0;
	rnd_aux = 0;
	rnd_aux_2 = 0;

	timer_still = SDL_GetTicks();

	//Making the Board pointer look at actual level


	int board_it = 0;

	if (App->lvl-1 <= 2) {
		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 8; x++) {
				board_copy[board_it] = App->scene_1to3->bubble_board[y][x];
				board_it++;
			}
		}
	}



	// Equation to Solve the bubble that will appear next, Works depending on the amount and type of bubble remaining

	board_it = 0;
	int Bubble_count[9];
	int total_bubs = 0;
	int columns = 0;
	int section = 1;

	for (int i = 0; i < 9; i++)
		Bubble_count[i] = 0;

	for (int i = 0; i < 96; i++){

		Bubble_count[board_copy[i]]++;

	}


	for (int i = 1; i < 9; i++)
		total_bubs += Bubble_count[i];


	rnd_aux = rand() % (total_bubs) + 1;

	rnd_aux--;

	for (int i = 1; i < 9; i++){

		if ((rnd_aux - Bubble_count[i]) <= 0){

			rnd_aux = section;
			break;
		}

		rnd_aux -= Bubble_count[i];

		section++;
	}


	Bubble_count[9];
	total_bubs = 0;
	columns = 0;
	section = 1;

	for (int i = 0; i < 9; i++)
		Bubble_count[i] = 0;

	for (int i = 0; i < 96; i++){

		Bubble_count[board_copy[i]]++;

	}


	for (int i = 1; i < 9; i++)
		total_bubs += Bubble_count[i];


	rnd_aux_2 = rand() % (total_bubs)+1;

	rnd_aux_2--;

	for (int i = 1; i < 9; i++){

		if ((rnd_aux_2 - Bubble_count[i]) <= 0){

			rnd_aux_2 = section;
			break;
		}

		rnd_aux_2 -= Bubble_count[i];

		section++;
	}

	LOG("Player Start end");

	return ret;
}


update_status ModulePlayer::Update()
{
	if (SDL_GetTicks() > timer_secs + 1500) {
		if (enable_once == false) {
			App->input->Enable();
			timer_shot = SDL_GetTicks();
			enable_once = true;
		}
	}
	else {
		App->render->Blit(sign_graphics, 87, 50, &round_sign);
		App->render->Blit(greenbub_graphics, 107, 56, &round_greenbub);
		switch (App->lvl) {
		case 1:
			greenbub_num.x = 63;
			break;
		case 2:
			greenbub_num.x = 77;
			break;
		case 3:
			greenbub_num.x = 91;
			break;
		}
		App->render->Blit(greenbub_graphics, 142, 75, &greenbub_num);
	}

	if (App->input->IsEnabled() && App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && player_angle > 5 && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_IDLE) {
		timer_still = SDL_GetTicks();
		if (player_angle <= 90) arrow_pos++;
		else arrow_pos--;
		player_angle -= ANGLE_INCREMENT;

		bmachine_pos++;


		if (change_sprite == 2){
			crank_pos--;
			bubwheel_pos--;
			smachine_pos++;
			change_sprite = 0;
		}

		change_sprite++;
	}

	if (App->input->IsEnabled() && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && player_angle < 175) {
		if (player_angle >= 90) arrow_pos++;
		else arrow_pos--;
		player_angle += ANGLE_INCREMENT;

		bmachine_pos--;


		if (change_sprite == 2){
			crank_pos++;
			bubwheel_pos++;
			smachine_pos--;
			change_sprite = 0;
		}

		change_sprite++;
	}



	if (App->input->IsEnabled() && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && App->particles->active[0] == nullptr) {
		timer_still = SDL_GetTicks();
		PlayerShoot();
		timer_shot = SDL_GetTicks();
	}

	if (App->input->keyboard[SDL_SCANCODE_TAB] == KEY_STATE::KEY_DOWN && App->particles->active[0] == nullptr) {
		App->debug_mode = !App->debug_mode;
	}

	// BLITS


	// Bag blit

	App->render->Blit(graphics, 72, 194, &bag[0], 0.75f);


	// Small Machine blit

	if (smachine_pos == 2) smachine_pos = 0;
	else if (smachine_pos == -1) smachine_pos = 1;

	App->render->Blit(graphics, 134, 177, &s_machine[smachine_pos], 0.75f);

	// Big Machine blit

	if (bmachine_pos == 12) bmachine_pos = 0;
	else if (bmachine_pos == -1) bmachine_pos = 11;

	App->render->Blit(graphics, 119, 193, &b_machine[bmachine_pos], 0.75f);

	// Arrow blit

	if (player_angle >= 90)
		App->render->Blit(graphics, position.x, position.y, &arrow[arrow_pos], 0.75f);

	else if (player_angle < 90)
		App->render->BlitRotation(graphics, position.x, position.y, &arrow[arrow_pos], 0, NULL, NULL, SDL_FLIP_HORIZONTAL);

	// Crank blit

	if (crank_pos == 8) crank_pos = 0;
	else if (crank_pos == -1) crank_pos = 7;

	App->render->Blit(graphics, 168, 200, &crank[crank_pos], 0.75f);

	// Bub ball blit

	hurry = &Bub_hurry;
	shoot = &Bub_shoot;
	stand = &Bub_stand;

	if (App->input->IsEnabled() && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && anim_shoot == false){

		anim_shoot = true;
		get_shoot = true;
	}

	else if (anim_shoot == true){

		if (get_shoot == true){
			shoot_int = SDL_GetTicks();
			get_shoot = false;
		}

		//App->render->Blit(graphics, 120, 198, &(shoot->GetCurrentFrame()));

		if (SDL_GetTicks() >= shoot_int && SDL_GetTicks() < shoot_int + 100) App->render->Blit(graphics, 120, 198, &bub_ball[7], 0.75f);
		if (SDL_GetTicks() >= shoot_int + 80 && SDL_GetTicks() < shoot_int + 160) App->render->Blit(graphics, 120, 198, &bub_ball[8], 0.75f);
		if (SDL_GetTicks() >= shoot_int + 160 && SDL_GetTicks() < shoot_int + 240) App->render->Blit(graphics, 120, 198, &bub_ball[9], 0.75f);
		if (SDL_GetTicks() >= shoot_int + 240 && SDL_GetTicks() < shoot_int + 320) App->render->Blit(graphics, 120, 198, &bub_ball[0], 0.75f);
		if (SDL_GetTicks() >= shoot_int + 320 && SDL_GetTicks() < shoot_int + 400) App->render->Blit(graphics, 120, 198, &bub_ball[4], 0.75f);
		if (SDL_GetTicks() >= shoot_int + 400 && SDL_GetTicks() < shoot_int + 480) App->render->Blit(graphics, 120, 198, &bub_ball[5], 0.75f);
		if (SDL_GetTicks() >= shoot_int + 480 && SDL_GetTicks() < shoot_int + 560) App->render->Blit(graphics, 120, 198, &bub_ball[6], 0.75f);
		if (SDL_GetTicks() >= shoot_int + 560 && SDL_GetTicks() < shoot_int + 640) App->render->Blit(graphics, 120, 198, &bub_ball[0], 0.75f);

		if (SDL_GetTicks() >= shoot_int + 620) {
			App->render->Blit(graphics, 120, 198, &bub_ball[0], 0.75f);
			anim_shoot = false;
		}
	}

	else if (timer_shot > 3500 && SDL_GetTicks() > timer_shot + 4500 && SDL_GetTicks() < timer_shot + 5000 || SDL_GetTicks() > timer_shot + 5500 && SDL_GetTicks() < timer_shot + 6000 || SDL_GetTicks() > timer_shot + 6500 && SDL_GetTicks() < timer_shot + 7000 || SDL_GetTicks() > timer_shot + 7500 && SDL_GetTicks() < timer_shot + 8000 || SDL_GetTicks() > timer_shot + 8500 && SDL_GetTicks() < timer_shot + 9000){
		App->render->Blit(graphics, 120, 198, &(hurry->GetCurrentFrame()));
	}

	else if (SDL_GetTicks() % 2000 == 10) App->render->Blit(graphics, 120, 198, &(stand->GetCurrentFrame()));

	else App->render->Blit(graphics, 120, 198, &bub_ball[0], 0.75f);

	// Bub wheel blit

	if (App->input->IsEnabled() && App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT || App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT){

		if (bubwheel_pos >= 8) bubwheel_pos = 0;
		else if (bubwheel_pos <= -1) bubwheel_pos = 7;

		App->render->Blit(graphics, 171, 198, &bub_wheel[bubwheel_pos], 0.75f);
	}

	else {

		//animation of BUB yawning
		
		//yawn = &BUB_yawn;
		
		if (SDL_GetTicks() > timer_still + 4000) {
			App->render->Blit(graphics, 171, 198, &(yawn->GetCurrentFrame()));
		}
		else 
		App->render->Blit(graphics, 171, 198, &bub_wheel[8], 0.75f);
	}

	// Tube blit

	App->render->Blit(graphics, 143, 201, &tube, 0.75f);

	// SHOOTING AFTER 10 SECS

	if (SDL_GetTicks() > timer_shot + 9000) {
		PlayerShoot();
		timer_shot = SDL_GetTicks();
	}

	// MESSAGE

	if (timer_shot > 3500){

		// 5
		if (SDL_GetTicks() > timer_shot + 4000 && SDL_GetTicks() < timer_shot + 4500) {
			App->render->Blit(graphics, 80, 180, &messages[1], 0.75f);
		}

		// 4
		if (SDL_GetTicks() > timer_shot + 5000 && SDL_GetTicks() < timer_shot + 5500) {
			App->render->Blit(graphics, 80, 180, &messages[2], 0.75f);
		}

		// 3
		if (SDL_GetTicks() > timer_shot + 6000 && SDL_GetTicks() < timer_shot + 6500) {
			App->render->Blit(graphics, 80, 180, &messages[3], 0.75f);
		}

		// 2
		if (SDL_GetTicks() > timer_shot + 7000 && SDL_GetTicks() < timer_shot + 7500) {
			App->render->Blit(graphics, 80, 180, &messages[4], 0.75f);
		}

		// 1
		if (SDL_GetTicks() > timer_shot + 8000 && SDL_GetTicks() < timer_shot + 8500) {
			App->render->Blit(graphics, 80, 180, &messages[5], 0.75f);
		}

		// HURRY UP
		if (SDL_GetTicks() > timer_shot + 4500 && SDL_GetTicks() < timer_shot + 5000 || SDL_GetTicks() > timer_shot + 5500 && SDL_GetTicks() < timer_shot + 6000 || SDL_GetTicks() > timer_shot + 6500 && SDL_GetTicks() < timer_shot + 7000 || SDL_GetTicks() > timer_shot + 7500 && SDL_GetTicks() < timer_shot + 8000 || SDL_GetTicks() > timer_shot + 8500 && SDL_GetTicks() < timer_shot + 9000) {
			App->render->Blit(graphics, 80, 180, &messages[0], 0.75f);
		}

	}

// Change bubble

	if (App->debug_mode == true){

		if (App->input->IsEnabled() && App->input->keyboard[SDL_SCANCODE_F2] == KEY_STATE::KEY_DOWN){

			if (rnd_aux < 8)
				rnd_aux++;

			else rnd_aux = 1;

		}
	}

	// UI Blit
	if (App->debug_mode) {
		App->fonts->Blit(2, 217, 0, "DEBUG_MODE");
	}

	

	sprintf_s(score_text, 10, "%7d", score);
	sprintf_s(round_text, 15, "LEVEL_0%d", App->lvl + 3);
	App->fonts->Blit(35, 8, 0, score_text);
	App->fonts->Blit(25, 0, 0, "1UP");
	App->fonts->Blit(123, 217, 0, round_text);
	sprintf_s(credits_text, 15, "CREDITS_%d", App->credits);

	if (SDL_GetTicks() > last_time_credits + 2000) {
		show_credits = false;
	}
	if (show_credits == true)
		App->fonts->Blit(220, 217, 0, credits_text);

	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_DOWN) {
		Mix_PlayChannel(-1, sfx08, 0);
		show_credits = true;
		last_time_credits = SDL_GetTicks();
		if (App->credits < 99)
			App->credits++;
	}

	if (App->input->keyboard[SDL_SCANCODE_E] == KEY_DOWN && App->debug_mode == true) {
		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 8; x++) {
				App->scene_1to3->bubble_board[y][x] = E;
			}
		}
	}

	// Bubble to shoot

	switch (rnd_aux){

	case 1: App->render->Blit(graphics, 143, 186, &BluBub, 0.75f); break;
	case 2: App->render->Blit(graphics, 143, 186, &RedBub, 0.75f); break;
	case 3: App->render->Blit(graphics, 143, 186, &GreenBub, 0.75f); break;
	case 4: App->render->Blit(graphics, 143, 186, &YelBub, 0.75f); break;
	case 5: App->render->Blit(graphics, 143, 186, &BlkBub, 0.75f); break;
	case 6: App->render->Blit(graphics, 143, 186, &OraBub, 0.75f); break;
	case 7: App->render->Blit(graphics, 143, 186, &GreyBub, 0.75f); break;
	case 8: App->render->Blit(graphics, 143, 186, &PplBub, 0.75f); break;
	default: break;

	}

	// Bubble incoming

	switch (rnd_aux_2){

	case 1: App->render->Blit(graphics, 107, 202, &BluBub, 0.75f); break;
	case 2: App->render->Blit(graphics, 107, 202, &RedBub, 0.75f); break;
	case 3: App->render->Blit(graphics, 107, 202, &GreenBub, 0.75f); break;
	case 4: App->render->Blit(graphics, 107, 202, &YelBub, 0.75f); break;
	case 5: App->render->Blit(graphics, 107, 202, &BlkBub, 0.75f); break;
	case 6: App->render->Blit(graphics, 107, 202, &OraBub, 0.75f); break;
	case 7: App->render->Blit(graphics, 107, 202, &GreyBub, 0.75f); break;
	case 8: App->render->Blit(graphics, 107, 202, &PplBub, 0.75f); break;
	default: break;
	}

	//Changes made to not crash

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN && App->debug_mode) {
		if (App->lvl > 2)
			App->fade->FadeToBlack(App->scene_1to3, App->scene_mainmenu, FADE_SPEED);
		App->fade->FadeToBlack(App->scene_1to3, App->scene_1to3, FADE_SPEED);
	}
	return UPDATE_CONTINUE;
}

update_status ModulePlayer::PostUpdate() {
	if (App->debug_mode == true) {
		shots = 0;
		if (App->input->IsEnabled() && App->input->keyboard[SDL_SCANCODE_F] == KEY_DOWN) {
			shots = 6;
		}
		if (App->input->IsEnabled() && App->input->keyboard[SDL_SCANCODE_G] == KEY_DOWN) {
			shots = -1;
		}
	}

	return UPDATE_CONTINUE;
}

void ModulePlayer::PlayerShoot() {

	rnd = rnd_aux;
	rnd_aux = rnd_aux_2;
	App->particles->AddParticle(App->particles->Bubble[rnd], App->particles->Bubble[rnd].position.x, App->particles->Bubble[rnd].position.y, COLLIDER_PLAYER_SHOT);
	//Making the Board pointer look at actual level


	int board_it = 0;

	if (App->lvl - 1 <= 2) {
		for (int y = 0; y < 12; y++) {
			for (int x = 0; x < 8; x++) {
				board_copy[board_it] = App->scene_1to3->bubble_board[y][x];
				board_it++;
			}
		}
	}



	// Equation to Solve the bubble that will appear next, Works depending on the amount and type of bubble remaining

	board_it = 0;
	int Bubble_count[9];
	int total_bubs = 0;
	int columns = 0;
	int section = 1;

	for (int i = 0; i < 9; i++)
		Bubble_count[i] = 0;

	for (int i = 0; i < 96; i++){

		Bubble_count[board_copy[i]]++;

	}


	for (int i = 1; i < 9; i++)
		total_bubs += Bubble_count[i];

	rnd_aux_2 = rand() % (total_bubs)+1;


	for (int i = 1; i < 9; i++){

		if ((rnd_aux_2 - Bubble_count[i]) <= 0){

			rnd_aux_2 = section;
			break;
		}

		rnd_aux_2 -= Bubble_count[i];

		section++;
	}


	//for now I put rand to 2 so it is Red = 2

	//rnd = 3;



	//Shoot audio
	sfx01 = Mix_LoadWAV("Resources/Audio/SFX/SFX 01.wav");
	Mix_PlayChannel(-1, sfx01, 0);
}