
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


ModuleScene1to3::ModuleScene1to3()
{

	foreground.x = 88;
	foreground.y = 23;
	foreground.w = 145;
	foreground.h = 201;

	background.x = 9;
	background.y = 9;
	background.w = 310;
	background.h = 235;

	bubbles[R].x = 12;
	bubbles[R].y = 312;
	bubbles[R].w = 16;
	bubbles[R].h = 16;
		  
	bubbles[G].x = 318;
	bubbles[G].y = 260;
	bubbles[G].w = 16;
	bubbles[G].h = 16;
		  
	bubbles[B].x = 12;
	bubbles[B].y = 260;
	bubbles[B].w = 16;
	bubbles[B].h = 16;
		  
	bubbles[Y].x = 12;
	bubbles[Y].y = 338;
	bubbles[Y].w = 16;
	bubbles[Y].h = 16;

	level_info.x = 35;
	level_info.y = 1710;
	level_info.w = 310;
	level_info.h = 7;

	limit_line.x = 34;
	limit_line.y = 1688;
	limit_line.w = 127;
	limit_line.h = 4;
}

ModuleScene1to3::~ModuleScene1to3()
{}

bool ModuleScene1to3::Start()
{

	LOG("Loading 1-3 scene");

	int tmp[12][8] = {
		{ R, R, Y, Y, B, B, G, G },
		{ E, R, R, Y, Y, B, B, G },
		{ B, B, G, G, R, R, Y, Y },
		{ E, B, G, G, R, R, Y, Y },
		{ E, E, E, E, E, E, E, E },
		{ E, E, E, E, E, E, E, E },
		{ E, E, E, E, E, E, E, E },
		{ E, E, E, E, E, E, E, E },
		{ E, E, E, E, E, E, E, E },
		{ E, E, E, E, E, E, E, E },
		{ E, E, E, E, E, E, E, E },
		{ E, E, E, E, E, E, E, E }
	};

	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 8; x++) {
			bubble_board[y][x] = tmp[y][x];
		}
	}

	LOG("Loading textures");
	background_graphics = App->textures->Load("Sprites/Backgrounds/Background 1-3.png");
	foreground_graphics = App->textures->Load("Sprites/Backgrounds/Borders 1-3.png");
	game_sprites_graphics = App->textures->Load("Sprites/Game Sprites.png");


	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->collision->AddCollider({ 78, 15, 9, 215 }, COLLIDER_WALL);
	App->collision->AddCollider({ 78, 15, 145, 8}, COLLIDER_CEILING);
	App->collision->AddCollider({ 215, 15, 8, 215 }, COLLIDER_WALL);

	App->collision->AddCollider({ 86, 184, 129, 4 }, COLLIDER_PLAYER);

	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);

	for (int y = 0; y < 12; y++) {
		for (int x = 0; x < 8; x++) {
			switch(bubble_board[y][x]) {
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
			}
		}
	}


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

	return true;
}

update_status ModuleScene1to3::Update()
{
	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);

	App->render->Blit(game_sprites_graphics, 87, 184, &limit_line, 1.f);
	
	App->render->Blit(foreground_graphics, 79, 14, &foreground, 0.92f);

	App->render->Blit(game_sprites_graphics, 0, 217, &level_info, 1.f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		if (lvl_check = 3) App->fade->FadeToBlack(this, (Module*)App->scene_4to6);

	}

 	return UPDATE_CONTINUE;
}