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
	
	//all arrow animation frames
	arrow.PushBack({ 14, 514, 24, 55 });
	arrow.speed = 0.07f;
	arrow.loop = false;

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

	player_angle = 90;

	graphics = App->textures->Load("Sprites/Game Sprites.png");
	return ret;
}


update_status ModulePlayer::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && player_angle > 5) {
		//aqui va q giri la flecha
		player_angle -= 1;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && player_angle < 175) {
		player_angle += 1;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) {
		App->particles->AddParticle(App->particles->red_bubble, App->particles->red_bubble.position.x, App->particles->red_bubble.position.y);
	}
	
	App->render->Blit(graphics, position.x, position.y, &(arrow.GetCurrentFrame()), 0.75f);

	return UPDATE_CONTINUE;
}