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

	arrow[44].x = 149;
	arrow[44].y = 713;
	arrow[44].w = 50;
	arrow[44].h = 30;

	arrow[45].x = 213;
	arrow[45].y = 713;
	arrow[45].w = 50;
	arrow[45].h = 30;

	arrow[46].x = 277;
	arrow[46].y = 714;
	arrow[46].w = 51;
	arrow[46].h = 29;

	arrow[47].x = 342;
	arrow[47].y = 715;
	arrow[47].w = 51;
	arrow[47].h = 27;

	arrow[48].x = 406;
	arrow[48].y = 715;
	arrow[48].w = 52;
	arrow[48].h = 27;

	arrow[49].x = 471;
	arrow[49].y = 716;
	arrow[49].w = 51;
	arrow[49].h = 26;

	arrow[50].x = 535;
	arrow[50].y = 717;
	arrow[50].w = 52;
	arrow[50].h = 24;

	arrow[51].x = 20;
	arrow[51].y = 751;
	arrow[51].w = 52;
	arrow[51].h = 24;

	arrow[52].x = 84;
	arrow[52].y = 752;
	arrow[52].w = 53;
	arrow[52].h = 22;

	arrow[53].x = 148;
	arrow[53].y = 752;
	arrow[53].w = 53;
	arrow[53].h = 22;

	arrow[54].x = 212;
	arrow[54].y = 752;
	arrow[54].w = 53;
	arrow[54].h = 21;

	arrow[55].x = 276;
	arrow[55].y = 752;
	arrow[55].w = 54;
	arrow[55].h = 21;

	arrow[56].x = 341;
	arrow[56].y = 752;
	arrow[56].w = 53;
	arrow[56].h = 21;

	arrow[57].x = 404;
	arrow[57].y = 752;
	arrow[57].w = 54;
	arrow[57].h = 21;

	arrow[58].x = 468;
	arrow[58].y = 752;
	arrow[58].w = 54;
	arrow[58].h = 21;

	arrow[59].x = 532;
	arrow[59].y = 752;
	arrow[59].w = 54;
	arrow[59].h = 21;

	arrow[60].x = 19;
	arrow[60].y = 786;
	arrow[60].w = 54;
	arrow[60].h = 21;

	arrow[61].x = 83;
	arrow[61].y = 786;
	arrow[61].w = 54;
	arrow[61].h = 21;

	arrow[62].x = 148;
	arrow[62].y = 786;
	arrow[62].w = 53;
	arrow[62].h = 21;

	arrow[63].x = 212;
	arrow[63].y = 786;
	arrow[63].w = 53;
	arrow[63].h = 21;
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
		if (player_angle < 90) arrow_pos++;
		else if (player_angle >= 90) arrow_pos--;
	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && player_angle < 175) {
		player_angle += ANGLE_INCREMENT;
		if (player_angle < 90) arrow_pos--;
		else if (player_angle >= 90) arrow_pos++;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) {
		App->particles->AddParticle(App->particles->red_bubble, App->particles->red_bubble.position.x, App->particles->red_bubble.position.y, COLLIDER_PLAYER_SHOT);
	}
	
	if (player_angle >= 90)
		App->render->Blit(graphics, position.x, position.y, &arrow[0], 0.75f);

	else if (player_angle < 90)
		App->render->BlitRotation(graphics, position.x, position.y, &arrow[arrow_pos], 0, NULL, NULL, SDL_FLIP_HORIZONTAL);

	return UPDATE_CONTINUE;
}