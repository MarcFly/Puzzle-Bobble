
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
}

ModuleScene1to3::~ModuleScene1to3()
{}

bool ModuleScene1to3::Start()
{

	deadline_pos = 11;

	BUBBLE_OFFSET_X_ODD = 71;
	BUBBLE_OFFSET_Y = 8;
	BUBBLE_OFFSET_X_PAIR = 64;

	playonce = true;

	LOG("Loading 1-3 scene");

	sfx05 = nullptr;
	sfx05 = Mix_LoadWAV("Resources/Audio/SFX/SFX 05.wav");

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

	for (int x = 0; x < 8; x++) {
		if (bubble_board[deadline_pos][x]){
			if (playonce) {
				Mix_PlayChannel(-1, sfx05, 0);
				playonce = false;
			}
			App->player->score = 0;
			App->fade->FadeToBlack(this, (Module*)App->scene_gameover);
		}
	}

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

	if (empty == true){
		if (App->lvl > 2)
			App->fade->FadeToBlack(this, (Module*)App->scene_win);

		else{
			
			App->fade->FadeToBlack(this, this);
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

	switch (App->player->shots) {
	case 4:
		//if (BUBBLE_OFFSET_X_ODD < 73)
		//	BUBBLE_OFFSET_X_ODD += 2;
		//else
		//	BUBBLE_OFFSET_X_ODD -= 2;
		//
		//if (BUBBLE_OFFSET_X_PAIR < 66)
		//	BUBBLE_OFFSET_X_PAIR += 2;
		//else
		//	BUBBLE_OFFSET_X_PAIR -= 2;

		break;
	case 5:
		break;
	case 6: 
		BUBBLE_OFFSET_Y += FALLING_CEILING_SPEED;
		deadline_pos--;
		col_ceiling->rect.y += FALLING_CEILING_SPEED;
		col_ceiling->SetPos(col_ceiling->rect.x, col_ceiling->rect.y);
		App->player->shots = 0;
		break;
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