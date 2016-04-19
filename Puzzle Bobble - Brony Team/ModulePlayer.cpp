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
	arrow[0].h = 54;

	arrow[1].x = 49;
	arrow[1].y = 515;
	arrow[1].w = 21;
	arrow[1].h = 54;

	arrow[2].x = 83;
	arrow[2].y = 515;
	arrow[2].w = 21;
	arrow[2].h = 54;

	arrow[3].x = 117;
	arrow[3].y = 515;
	arrow[3].w = 21;
	arrow[3].h = 54;

	arrow[4].x = 151;
	arrow[4].y = 515;
	arrow[4].w = 21;
	arrow[4].h = 54;

	arrow[5].x = 185;
	arrow[5].y = 515;
	arrow[5].w = 21;
	arrow[5].h = 54;

	arrow[6].x = 219;
	arrow[6].y = 515;
	arrow[6].w = 21;
	arrow[6].h = 54;

	arrow[7].x = 253;
	arrow[7].y = 516;
	arrow[7].w = 21;
	arrow[7].h = 54;

	arrow[8].x = 287;
	arrow[8].y = 515;
	arrow[8].w = 21;
	arrow[8].h = 53;

	arrow[9].x = 321;
	arrow[9].y = 516;
	arrow[9].w = 21;
	arrow[9].h = 54;

	arrow[10].x = 355;
	arrow[10].y = 516;
	arrow[10].w = 21;
	arrow[10].h = 53;

	arrow[11].x = 389;
	arrow[11].y = 516;
	arrow[11].w = 22;
	arrow[11].h = 53;

	arrow[12].x = 423;
	arrow[12].y = 516;
	arrow[12].w = 22;
	arrow[12].h = 53;

	arrow[13].x = 456;
	arrow[13].y = 517;
	arrow[13].w = 23;
	arrow[13].h = 53;

	arrow[14].x = 490;
	arrow[14].y = 517;
	arrow[14].w = 23;
	arrow[14].h = 52;

	arrow[15].x = 523;
	arrow[15].y = 517;
	arrow[15].w = 25;
	arrow[15].h = 52;

	arrow[16].x = 557;
	arrow[16].y = 517;
	arrow[16].w = 26;
	arrow[16].h = 52;

	arrow[17].x = 591;
	arrow[17].y = 517;
	arrow[17].w = 26;
	arrow[17].h = 52;

	arrow[18].x = 12;
	arrow[18].y = 584;
	arrow[18].w = 28;
	arrow[18].h = 50;

	arrow[19].x = 46;
	arrow[19].y = 584;
	arrow[19].w = 29;
	arrow[19].h = 50;

	arrow[20].x = 79;
	arrow[20].y = 584;
	arrow[20].w = 30;
	arrow[20].h = 50;

	arrow[21].x = 113;
	arrow[21].y = 585;
	arrow[21].w = 31;
	arrow[21].h = 49;

	arrow[22].x = 147;
	arrow[22].y = 585;
	arrow[22].w = 32;
	arrow[22].h = 49;

	arrow[23].x = 196;
	arrow[23].y = 586;
	arrow[23].w = 33;
	arrow[23].h = 48;

	arrow[24].x = 246;
	arrow[24].y = 586;
	arrow[24].w = 34;
	arrow[24].h = 48;

	arrow[25].x = 295;
	arrow[25].y = 586;
	arrow[25].w = 35;
	arrow[25].h = 47;

	arrow[26].x = 345;
	arrow[26].y = 586;
	arrow[26].w = 36;
	arrow[26].h = 47;

	arrow[27].x = 395;
	arrow[27].y = 587;
	arrow[27].w = 37;
	arrow[27].h = 46;

	arrow[28].x = 444;
	arrow[28].y = 588;
	arrow[28].w = 38;
	arrow[28].h = 44;

	arrow[29].x = 494;
	arrow[29].y = 588;
	arrow[29].w = 38;
	arrow[29].h = 44;

	arrow[30].x = 544;
	arrow[30].y = 588;
	arrow[30].w = 39;
	arrow[30].h = 44;
	
	arrow[31].x = 23;
	arrow[31].y = 655;
	arrow[31].w = 41;
	arrow[31].h = 43;

	arrow[32].x = 73;
	arrow[32].y = 656;
	arrow[32].w = 42;
	arrow[32].h = 41;

	arrow[33].x = 123;
	arrow[33].y = 656;
	arrow[33].w = 42;
	arrow[33].h = 41;

	arrow[34].x = 173;
	arrow[34].y = 656;
	arrow[34].w = 42;
	arrow[34].h = 41;

	arrow[35].x = 222;
	arrow[35].y = 657;
	arrow[35].w = 44;
	arrow[35].h = 40;

	arrow[36].x = 272;
	arrow[36].y = 658;
	arrow[36].w = 44;
	arrow[36].h = 38;

	arrow[37].x = 322;
	arrow[37].y = 659;
	arrow[37].w = 45;
	arrow[37].h = 37;

	arrow[38].x = 372;
	arrow[38].y = 659;
	arrow[38].w = 45;
	arrow[38].h = 37;

	arrow[39].x = 421;
	arrow[39].y = 659;
	arrow[39].w = 47;
	arrow[39].h = 36;

	arrow[40].x = 472;
	arrow[40].y = 660;
	arrow[40].w = 47;
	arrow[40].h = 35;

	arrow[41].x = 524;
	arrow[41].y = 661;
	arrow[41].w = 48;
	arrow[41].h = 33;
	
	arrow[42].x = 21;
	arrow[42].y = 712;
	arrow[42].w = 48;
	arrow[42].h = 32;

	arrow[43].x = 85;
	arrow[43].y = 712;
	arrow[43].w = 48;
	arrow[43].h = 32;

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
		if (player_angle <= 90) arrow_pos++;
		else if (player_angle > 90) arrow_pos--;
		player_angle -= ANGLE_INCREMENT;

	}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && player_angle < 175) {
		if (player_angle < 90) arrow_pos--;
		else if (player_angle >= 90) arrow_pos++;
		player_angle += ANGLE_INCREMENT;

	}

	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) {
		App->particles->AddParticle(App->particles->red_bubble, App->particles->red_bubble.position.x, App->particles->red_bubble.position.y, COLLIDER_PLAYER_SHOT);
	}
	
	if (player_angle >= 90)
		App->render->Blit(graphics, position.x, position.y, &arrow[arrow_pos], 0.75f);

	else if (player_angle < 90)
		App->render->BlitRotation(graphics, position.x, position.y, &arrow[arrow_pos], 0, NULL, NULL, SDL_FLIP_HORIZONTAL);

	return UPDATE_CONTINUE;
}