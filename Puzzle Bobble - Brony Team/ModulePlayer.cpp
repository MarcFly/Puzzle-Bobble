#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "PuzzleBubble/ModuleParticles.h"

#define ANGLE_INCREMENT 85.f/63.f


ModulePlayer::ModulePlayer()
{
	position.x = 139;
	position.y = 163;
	
	//all arrow animation frames

	//Central
	arrow[0].x = 15;
	arrow[0].y = 514;
	arrow[0].w = 22;
	arrow[0].h = 55;

	arrow[1].x = 14;
	arrow[1].y = 514;
	arrow[1].w = 24;
	arrow[1].h = 55;

	arrow[2].x = 14;
	arrow[2].y = 514;
	arrow[2].w = 24;
	arrow[2].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[9].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[14].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[20].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[26].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[32].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[38].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[44].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[50].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[56].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[3].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[62].x = 14;
	arrow[3].y = 514;
	arrow[3].w = 24;
	arrow[3].h = 55;

	arrow[63].x = 14;
	arrow[63].y = 514;
	arrow[63].w = 24;
	arrow[63].h = 55;
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
		player_angle -= ANGLE_INCREMENT;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && player_angle < 175) {
		player_angle += ANGLE_INCREMENT;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) {
		App->particles->AddParticle(App->particles->red_bubble, App->particles->red_bubble.position.x, App->particles->red_bubble.position.y, COLLIDER_PLAYER_SHOT);
	}
	
	App->render->Blit(graphics, position.x, position.y, &arrow[0], 0.75f);

	return UPDATE_CONTINUE;
}