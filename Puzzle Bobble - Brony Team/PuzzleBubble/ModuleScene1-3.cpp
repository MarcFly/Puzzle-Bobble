
#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "../ModuleInput.h"
#include "ModuleScene1-3.h"
#include "../ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleParticles.h"
#include "../ModuleCollision.h"
#include "../ModuleEnemies.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include <stdio.h>


ModuleScene1to3::ModuleScene1to3()
{

	wall.x = 88;
	wall.y = 23;
	wall.w = 9;
	wall.h = 215;

	ceiling.x = 97;
	ceiling.y = 23;
	ceiling.w = 197;
	ceiling.h = 9;

	background.x = 9;
	background.y = 9;
	background.w = 310;
	background.h = 235;

	top_background.x = 9;
	top_background.y = 9;
	top_background.w = 310;
	top_background.h = 15;

	level_info.x = 35;
	level_info.y = 1710;
	level_info.w = 310;
	level_info.h = 7;

	limit_line.x = 34;
	limit_line.y = 1688;
	limit_line.w = 127;
	limit_line.h = 4;

	falling_ceiling.x = 97;
	falling_ceiling.y = 24;
	falling_ceiling.w = 127;
	falling_ceiling.h = 162;

	round_clear.x = 4;
	round_clear.y = 76;
	round_clear.w = 177;
	round_clear.h = 16;

	PTS.x = 4;
	PTS.y = 94;
	PTS.w = 51;
	PTS.h = 17;

	SEC.x = 62;
	SEC.y = 94;
	SEC.w = 51;
	SEC.h = 17;

	NOBONUS.x = 119;
	NOBONUS.y = 93;
	NOBONUS.w = 126;
	NOBONUS.h = 18;

}

ModuleScene1to3::~ModuleScene1to3()
{}

bool ModuleScene1to3::Start()
{

	App->particles->Enable();

	play_sfx13_once = false;

	shake_timer_once = false;
	time_once = false;

	is_gameover = false;

	death_timer = 0;
	death_once = false;

	win_timer = 0;
	win_once = false;

	deadline_pos = 11;

	BUBBLE_OFFSET_X_ODD = 71;
	BUBBLE_OFFSET_Y = 8;
	BUBBLE_OFFSET_X_PAIR = 64;

	playonce = true;

	LOG("Loading 1-3 scene");

	sfx13 = nullptr;
	sfx13 = Mix_LoadWAV("Resources/Audio/SFX/SFX 13.wav");
	sfx09 = nullptr;
	sfx09 = Mix_LoadWAV("Resources/Audio/SFX/SFX 09.wav");
	sfx07 = nullptr;
	sfx07 = Mix_LoadWAV("Resources/Audio/SFX/SFX 07.wav");

	int tmp[3][12][8] = {

		//LEVEL 1
		{
		
			{ E, V, V, E, E, B, B, E },
			{ E, E, g, E, E, E, R, E },
			{ E, G, E, E, E, B, E, E },
			{ E, E, G, E, E, E, P, E },
			{ E, B, E, E, E, R, E, E },
			{ E, E, R, E, E, E, B, E },
			{ E, g, E, E, E, R, E, E },
			{ E, E, P, E, E, E, g, E },
			{ E, E, E, E, E, E, E, E },
			{ E, E, E, E, E, E, E, E },
			{ E, E, E, E, E, E, E, E },
			{ E, E, E, E, E, E, E, E }
			

		},

		//LEVEL 2
		{
			{ E, P, E, Y, E, B, E, P },
			{ E, G, E, R, E, R, E, B },
			{ B, E, P, E, O, E, Y, E },
			{ E, E, G, E, G, E, B, E },
			{ E, B, E, B, E, O, E, E },
			{ E, Y, E, Y, E, B, E, E },
			{ E, E, P, E, B, E, E, E },
			{ E, E, E, E, G, E, E, E },
			{ E, E, E, E, E, E, E, E },
			{ E, E, E, E, E, E, E, E },
			{ E, E, E, E, E, E, E, E },
			{ E, E, E, E, E, E, E, E }
		},

		//LEVEL 3
		{
			{ B, G, B, B, G, P, R, g },
			{ E, B, E, Y, E, R, E, B },
			{ E, Y, R, B, B, Y, g, E },
			{ E, E, R, E, R, E, Y, E },
			{ E, Y, Y, g, G, R, P, E },
			{ E, g, E, R, E, G, E, R },
			{ g, B, B, G, R, Y, P, B },
			{ E, E, E, E, E, E, E, E },
			{ E, E, E, E, E, E, E, E },
			{ E, E, E, E, E, E, E, E },
			{ E, E, E, E, E, E, E, E },
			{ E, E, E, E, E, E, E, E }
		},
	};

	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 8; x++) {
			bubble_board[y][x] = tmp[App->lvl-1][y][x];
			prev_bb[y][x] = tmp[App->lvl-1][y][x];
		}
	}


	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 8; x++) {
			switch (bubble_board[y][x]) {
			case R:
				if (y % 2)
					App->enemies->AddEnemy(BOBBLE_RED, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				else
					App->enemies->AddEnemy(BOBBLE_RED, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				break;
			case G:
				if (y % 2)
					App->enemies->AddEnemy(BOBBLE_GREEN, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				else
					App->enemies->AddEnemy(BOBBLE_GREEN, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				break;
			case B:
				if (y % 2)
					App->enemies->AddEnemy(BOBBLE_BLUE, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				else
					App->enemies->AddEnemy(BOBBLE_BLUE, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				break;
			case Y:
				if (y % 2)
					App->enemies->AddEnemy(BOBBLE_YELLOW, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				else
					App->enemies->AddEnemy(BOBBLE_YELLOW, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				break;
			case g:
				if (y % 2)
					App->enemies->AddEnemy(BOBBLE_GREY, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				else
					App->enemies->AddEnemy(BOBBLE_GREY, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				break;
			case V:
				if (y % 2)
					App->enemies->AddEnemy(BOBBLE_BLACK, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				else
					App->enemies->AddEnemy(BOBBLE_BLACK, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				break;
			case P:
				if (y % 2)
					App->enemies->AddEnemy(BOBBLE_PURPLE, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				else
					App->enemies->AddEnemy(BOBBLE_PURPLE, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				break;
			case O:
				if (y % 2)
					App->enemies->AddEnemy(BOBBLE_ORANGE, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				else
					App->enemies->AddEnemy(BOBBLE_ORANGE, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
				break;
			}
		}
	}

	LOG("Loading textures");
	background_graphics = App->textures->Load("Resources/Sprites/Background 4-6.png");
	foreground_graphics = App->textures->Load("Resources/Sprites/Borders 4-6.png");
	game_sprites_graphics = App->textures->Load("Resources/Sprites/Game Sprites.png");
	falling_graphics = App->textures->Load("Resources/Sprites/falling_ceiling2.png");
	greenbubfont_graphics = App->textures->Load("Resources/Sprites/GreenBubFont.png");

	font_greenbub = App->fonts->Load("Resources/Sprites/GreenBubFont.png", " !@,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->collision->AddCollider({ 78, 15, 9, 215 }, COLLIDER_WALL);
	col_ceiling = App->collision->AddCollider({ 78, 15, 145, 8}, COLLIDER_CEILING);
	App->collision->AddCollider({ 215, 15, 8, 215 }, COLLIDER_WALL);

	//App->collision->AddCollider({ 86, 184, 129, 4 }, COLLIDER_PLAYER);

	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);

	Mix_PlayMusic(App->audio->music03, -1);

	shake = false;

	last_time = 0;



	return true;
}

// UnLoad assets
bool ModuleScene1to3::CleanUp()
{
	LOG("Unloading 1-3 scene");
	App->textures->Unload(background_graphics);
	App->textures->Unload(foreground_graphics);
	App->textures->Unload(game_sprites_graphics);
	App->player->Disable();
	App->particles->Disable();
	App->collision->Disable();
	App->enemies->Disable();
	App->input->Disable();

	App->lvl++;

	return true;
}

update_status ModuleScene1to3::Update()
{

	// GRAPHIC RENDERS
	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);
	
	App->render->Blit(falling_graphics, col_ceiling->rect.x + 10, col_ceiling->rect.y - 154, &falling_ceiling);

	App->render->Blit(game_sprites_graphics, 87, 184, &limit_line, 1.f);
	
	App->render->Blit(background_graphics, 0, 0, &top_background, 0.75f);
	App->render->Blit(foreground_graphics, 79, 14, &wall, 0.92f);
	App->render->Blit(foreground_graphics, 215, 14, &wall, 0.92f);
	App->render->Blit(foreground_graphics, 88, 14, &ceiling, 0.92f);

	App->render->Blit(game_sprites_graphics, 0, 217, &level_info, 1.f);
	
	// ----
	uint aux = deadline_pos;
	if (deadline_pos >= 11)
		deadline_pos = 10;
	for (int x = 0; x < 8; x++) {
		if (bubble_board[deadline_pos][x]){
			Mix_PauseMusic();
			is_gameover = true;
			App->input->Disable();
			App->particles->Disable();
			if (playonce) {
				Mix_PlayChannel(-1, sfx09, 0);
				playonce = false;
			}
			if (!death_once) {
				death_timer = SDL_GetTicks();
				death_once = !death_once;
			}
			if (SDL_GetTicks() > death_timer + 2000 && play_sfx13_once == false) {
				Mix_PlayChannel(-1, sfx13, 0);
				play_sfx13_once = true;
			}
			if (SDL_GetTicks() > death_timer + 3000)
				App->fade->FadeToBlack(this, (Module*)App->scene_gameover, FADE_SPEED);
		}
	}
	deadline_pos = aux;

	bool empty = true;

	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 8; x++) { 

			if (bubble_board[y][x] == E)
				empty = true;

			else{
				empty = false;
				break;
			}
		}

		if (empty == false)
			break;

	}

	int lvl_time = (SDL_GetTicks() - App->player->timer_secs) / 1500;

	if (empty == true){

		if (lvl_time <= 64 && App->input->enabled == true){

			if (lvl_time > 5){
				App->player->score += (50000 / 60) * (60 - lvl_time);
				sprintf_s(time_score, 10, "%7d", (50000 / 60) * (60 - lvl_time));
			}

			else{

				App->player->score += 50000;
				sprintf_s(time_score, 10, "%7d", 50000);
			}
			if (App->player->score >= 999999999)
				App->player->score = 999999999;
		}
			if (time_once == false) {
				time_spent = lvl_time;
				time_once = true;
			}

		App->particles->Disable();
		App->input->Disable();
		
		if (win_once == false){
			win_timer = SDL_GetTicks();
			Mix_PlayMusic(App->audio->music04, 1);
			win_once = true;
		}
		if (SDL_GetTicks() < win_timer + 2000) {
			App->render->Blit(greenbubfont_graphics, 64, 75, &round_clear);
		}
		if (SDL_GetTicks() > win_timer + 2000) {
			sprintf_s(secs_needed, 10, "%d", time_spent);
			if (time_spent <= 64) {
				App->fonts->Blit(61, 100, 1, time_score);
				App->render->Blit(greenbubfont_graphics, 163, 100, &PTS);
			}
			else
				App->render->Blit(greenbubfont_graphics, 85, 100, &NOBONUS);
			
			if (time_spent >= 100)
				App->fonts->Blit(97, 65, 1, secs_needed);
			else 
				App->fonts->Blit(105, 65, 1, secs_needed);
			App->render->Blit(greenbubfont_graphics, 148, 65, &SEC);
		}
		if (SDL_GetTicks() > win_timer + 4000) {
			if (App->lvl > 2) {
				App->fade->FadeToBlack(this, (Module*)App->scene_win, FADE_SPEED);
			}
			else{
				App->fade->FadeToBlack(this, this, FADE_SPEED);
			}
		}
	}

 	return UPDATE_CONTINUE;
}

update_status ModuleScene1to3::PostUpdate(){

	to_erase = false;

	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 8; x++) {
			if (prev_bb[y][x] != bubble_board[y][x]) {
				to_erase = true;
			}
		}
	}

	if (is_gameover == false) {
		switch (App->player->shots) {
		case 6:
			BUBBLE_OFFSET_Y += FALLING_CEILING_SPEED;
			BUBBLE_OFFSET_X_ODD = 71;
			BUBBLE_OFFSET_X_PAIR = 64;
			deadline_pos--;
			col_ceiling->rect.y += FALLING_CEILING_SPEED;
			col_ceiling->SetPos(col_ceiling->rect.x, col_ceiling->rect.y);
			App->player->shots = 0;
			to_erase = true;
			shake = false;
			shake_timer_once = false;
			Mix_PlayChannel(-1, sfx07, 0);
			break;
		case -1: 
			if (BUBBLE_OFFSET_Y > 8) {
				BUBBLE_OFFSET_Y -= FALLING_CEILING_SPEED;
				BUBBLE_OFFSET_X_ODD = 71;
				BUBBLE_OFFSET_X_PAIR = 64;
				deadline_pos++;
				col_ceiling->rect.y -= FALLING_CEILING_SPEED;
				col_ceiling->SetPos(col_ceiling->rect.x, col_ceiling->rect.y);
				App->player->shots = 0;
				to_erase = true;
				shake = false;
				shake_timer_once = false;
				Mix_PlayChannel(-1, sfx07, 0);
			}
			break;
		}

		if (App->player->shots == 4) {
			if (shake_timer_once == false) {
				shake_timer = SDL_GetTicks();
				shake_timer_once = true;
			}
			if (SDL_GetTicks() > shake_timer + 100) {
				to_erase = true;
				if (BUBBLE_OFFSET_X_ODD < 72)
					BUBBLE_OFFSET_X_ODD += 2;
				else
					BUBBLE_OFFSET_X_ODD -= 2;
				if (BUBBLE_OFFSET_X_PAIR < 65)
					BUBBLE_OFFSET_X_PAIR += 2;
				else
					BUBBLE_OFFSET_X_PAIR -= 2;
				shake_timer = SDL_GetTicks();
			}
		}
		if (App->player->shots == 5) {
			if (SDL_GetTicks() > shake_timer + 75) {
				to_erase = true;
				if (BUBBLE_OFFSET_X_ODD < 72)
					BUBBLE_OFFSET_X_ODD += 2;
				else
					BUBBLE_OFFSET_X_ODD -= 2;
				if (BUBBLE_OFFSET_X_PAIR < 65)
					BUBBLE_OFFSET_X_PAIR += 2;
				else
					BUBBLE_OFFSET_X_PAIR -= 2;
				shake_timer = SDL_GetTicks();
			}
		}
	}
	

			if (to_erase) {
				App->enemies->EraseAll();
				 
				for (int y = 0; y < 12; y++) {
					for (int x = 0; x < 8; x++) {
						switch (bubble_board[y][x]) {
						case R:
							if (y % 2)
								App->enemies->AddEnemy(BOBBLE_RED, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							else
								App->enemies->AddEnemy(BOBBLE_RED, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							break;
						case G:
							if (y % 2)
								App->enemies->AddEnemy(BOBBLE_GREEN, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							else
								App->enemies->AddEnemy(BOBBLE_GREEN, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							break;
						case B:
							if (y % 2)
								App->enemies->AddEnemy(BOBBLE_BLUE, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							else
								App->enemies->AddEnemy(BOBBLE_BLUE, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							break;
						case Y:
							if (y % 2)
								App->enemies->AddEnemy(BOBBLE_YELLOW, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							else
								App->enemies->AddEnemy(BOBBLE_YELLOW, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							break;
						case g:
							if (y % 2)
								App->enemies->AddEnemy(BOBBLE_GREY, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							else
								App->enemies->AddEnemy(BOBBLE_GREY, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							break;
						case V:
							if (y % 2)
								App->enemies->AddEnemy(BOBBLE_BLACK, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							else
								App->enemies->AddEnemy(BOBBLE_BLACK, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							break;
						case P:
							if (y % 2)
								App->enemies->AddEnemy(BOBBLE_PURPLE, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							else
								App->enemies->AddEnemy(BOBBLE_PURPLE, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							break;
						case O:
							if (y % 2)
								App->enemies->AddEnemy(BOBBLE_ORANGE, ((x + 1) * 16) + BUBBLE_OFFSET_X_PAIR, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							else
								App->enemies->AddEnemy(BOBBLE_ORANGE, ((x + 1) * 16) + BUBBLE_OFFSET_X_ODD, ((y + 1) * 15) + BUBBLE_OFFSET_Y);
							break;
					}
				}
			}
		}


	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 8; x++) {
			prev_bb[y][x] = bubble_board[y][x];
		}
	}

	
	LOG("SCENE PostUpdate")
	return UPDATE_CONTINUE;
}