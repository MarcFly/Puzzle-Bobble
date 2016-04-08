#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "PuzzleBubble/ModuleParticles.h"


ModulePlayer::ModulePlayer()
{
	position.x = 139;
	position.y = 155;
	
	arrow.x = 14;
	arrow.y = 514;
	arrow.w = 24;
	arrow.h = 55;

	//-----------
	

}

ModulePlayer::~ModulePlayer()
{}

bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;

	arrow_center.x = 50;
	arrow_center.y = 130;

	graphics = App->textures->Load("Sprites/Game Sprites.png");
	return ret;
}


update_status ModulePlayer::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && player_angle > 5) {
		player_angle -= 1;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && player_angle < 175) {
		player_angle += 1;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) {
		App->particles->AddParticle(App->particles->red_bubble, position.x, position.y - 25);
	}
	
	App->render->BlitRotation(graphics, position.x, position.y, &arrow, 0.75f, player_angle - 90, &arrow_center, SDL_FLIP_NONE);

	return UPDATE_CONTINUE;
}