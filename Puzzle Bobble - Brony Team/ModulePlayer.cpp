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

	idle.PushBack({15, 514, 23, 57});
	idle.speed = 0.05f;

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
	Animation* current_animation = &idle;

	SDL_Rect r = current_animation->GetCurrentFrame();

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		player_angle--;

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		player_angle++;

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) {
		App->particles->AddParticle(App->particles->red_bubble, position.x, position.y - 25);
	}

	App->render->Blit(graphics, position.x, position.y, &(current_animation->GetCurrentFrame()));
	
	return UPDATE_CONTINUE;
}