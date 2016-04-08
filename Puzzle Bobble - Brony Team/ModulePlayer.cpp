#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "PuzzleBubble/ModuleParticles.h"


ModulePlayer::ModulePlayer()
{
	position.x = 140;
	position.y = 170;
	
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


	graphics = App->textures->Load("Sprites/Game Sprites.png");
	return ret;
}


update_status ModulePlayer::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT) {
		player_angle -= 1;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) {
		player_angle += 1;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) {
		App->particles->AddParticle(App->particles->red_bubble, position.x, position.y - 25);
	}
	
	App->render->BlitRotation(graphics, 134, 155, &arrow, 0.75f, player_angle, NULL, SDL_FLIP_NONE);

	return UPDATE_CONTINUE;
}