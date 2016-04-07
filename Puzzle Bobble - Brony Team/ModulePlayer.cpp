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

	//Seting all arrows rectangles
	for (int i = 0; i < NUM_ARROW_SPRITES; i++) {
		arrow[i].w = 33;
		arrow[i].h = 62;
	}

	arrow[65].x = 11;
	arrow[65].y = 511;
	
	arrow[66].x = 44;
	arrow[66].y = 511;

	arrow[67].x = 77;
	arrow[67].y = 511;

	arrow[68].x = 111;
	arrow[68].y = 511;

	arrow[69].x = 145;
	arrow[69].y = 511;
	

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
		current_arrow--;
		player_angle--;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT) {
		current_arrow++;
		player_angle++;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) {
		App->particles->AddParticle(App->particles->red_bubble, position.x, position.y - 25);
	}
	
	App->render->Blit(graphics, 134, 155, &arrow[current_arrow], 0.75f);

	return UPDATE_CONTINUE;
}