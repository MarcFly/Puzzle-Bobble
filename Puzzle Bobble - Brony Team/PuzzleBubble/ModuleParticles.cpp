#include <math.h>
#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "ModuleParticles.h"
#include "../ModulePlayer.h"
#include "../ModuleCollision.h"
#include "ModuleScene1-3.h"
#include "ModuleAudio.h"

#define BUBBLE_SPEED 5.f

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
//for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
//	active[i] = nullptr;
for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = new Particle;
}

ModuleParticles::~ModuleParticles()
{}

bool ModuleParticles::Start()
{
	sfx03 = nullptr;
	sfx02 = nullptr;
	sfx02 = Mix_LoadWAV("Resources/Audio/SFX/SFX 02.wav");

	LOG("Loading particles");
	graphics = App->textures->Load("Resources/Sprites/Player sprites.png");

	Bubble[0].life = 0;

	// Blue Bubble particle
	Bubble[1].anim.PushBack({ 18, 559, 16, 16 });
	Bubble[1].anim.PushBack({ 35, 559, 16, 16 });
	Bubble[1].anim.PushBack({ 52, 559, 16, 16 });
	Bubble[1].anim.PushBack({ 69, 559, 16, 16 });
	Bubble[1].anim.PushBack({ 86, 559, 16, 16 });
	Bubble[1].anim.PushBack({ 103, 559, 16, 16 });
	Bubble[1].anim.PushBack({ 120, 559, 16, 16 });
	Bubble[1].anim.PushBack({ 137, 559, 16, 16 });
	Bubble[1].anim.PushBack({ 154, 559, 16, 16 });
	Bubble[1].anim.loop = false;
	Bubble[1].anim.speed = 0.11111f;
	Bubble[1].life = -1;
	Bubble[1].position.x = 143;
	Bubble[1].position.y = 190;

	// Red Bubble particle
	Bubble[2].anim.PushBack({ 18, 607, 16, 16 });
	Bubble[2].anim.PushBack({ 69, 607, 16, 16 });
	Bubble[2].anim.PushBack({ 86, 607, 16, 16 });
	Bubble[2].anim.PushBack({ 103, 607, 16, 16 });
	Bubble[2].anim.PushBack({ 120, 607, 16, 16 });
	Bubble[2].anim.PushBack({ 137, 607, 16, 16 });
	Bubble[2].anim.PushBack({ 154, 607, 16, 16 });
	Bubble[2].anim.loop = false;
	Bubble[2].anim.speed = 0.2f;
	Bubble[2].life = -1;
	Bubble[2].position.x = 143;
	Bubble[2].position.y = 190;

	// Green Bubble particle
	Bubble[3].anim.PushBack({ 266, 559, 16, 16 });
	Bubble[3].anim.PushBack({ 283, 559, 16, 16 });
	Bubble[3].anim.PushBack({ 300, 559, 16, 16 });
	Bubble[3].anim.PushBack({ 317, 559, 16, 16 });
	Bubble[3].anim.PushBack({ 334, 559, 16, 16 });
	Bubble[3].anim.PushBack({ 351, 559, 16, 16 });
	Bubble[3].anim.PushBack({ 368, 559, 16, 16 });
	Bubble[3].anim.PushBack({ 385, 559, 16, 16 });
	Bubble[3].anim.PushBack({ 402, 559, 16, 16 });
	Bubble[3].anim.loop = false;
	Bubble[3].anim.speed = 0.11111f;
	Bubble[3].life = -1;
	Bubble[3].position.x = 143;
	Bubble[3].position.y = 190;

	// Yellow Bubble particle
	Bubble[4].anim.PushBack({ 18, 631, 16, 16 });
	Bubble[4].anim.PushBack({ 35, 631, 16, 16 });
	Bubble[4].anim.PushBack({ 52, 631, 16, 16 });
	Bubble[4].anim.PushBack({ 69, 631, 16, 16 });
	Bubble[4].anim.PushBack({ 86, 631, 16, 16 });
	Bubble[4].anim.PushBack({ 103, 631, 16, 16 });
	Bubble[4].anim.PushBack({ 120, 631, 16, 16 });
	Bubble[4].anim.PushBack({ 137, 631, 16, 16 });
	Bubble[4].anim.PushBack({ 154, 631, 16, 16 });
	Bubble[4].anim.loop = false;
	Bubble[4].anim.speed = 0.11111f;
	Bubble[4].life = -1;
	Bubble[4].position.x = 143;
	Bubble[4].position.y = 190;

	// Black Bubble particle
	Bubble[5].anim.PushBack({ 266, 583, 16, 16 });
	Bubble[5].anim.PushBack({ 283, 583, 16, 16 });
	Bubble[5].anim.PushBack({ 300, 583, 16, 16 });
	Bubble[5].anim.PushBack({ 317, 583, 16, 16 });
	Bubble[5].anim.PushBack({ 334, 583, 16, 16 });
	Bubble[5].anim.PushBack({ 351, 583, 16, 16 });
	Bubble[5].anim.PushBack({ 368, 583, 16, 16 });
	Bubble[5].anim.PushBack({ 385, 583, 16, 16 });
	Bubble[5].anim.PushBack({ 402, 583, 16, 16 });
	Bubble[5].anim.loop = false;
	Bubble[5].anim.speed = 0.11111f;
	Bubble[5].life = -1;
	Bubble[5].position.x = 143;
	Bubble[5].position.y = 190;

	// Orange Bubble particle
	Bubble[6].anim.PushBack({ 266, 607, 16, 16 });
	Bubble[6].anim.PushBack({ 283, 607, 16, 16 });
	Bubble[6].anim.PushBack({ 300, 607, 16, 16 });
	Bubble[6].anim.PushBack({ 317, 607, 16, 16 });
	Bubble[6].anim.PushBack({ 334, 607, 16, 16 });
	Bubble[6].anim.PushBack({ 351, 607, 16, 16 });
	Bubble[6].anim.PushBack({ 368, 607, 16, 16 });
	Bubble[6].anim.PushBack({ 385, 607, 16, 16 });
	Bubble[6].anim.PushBack({ 402, 607, 16, 16 });
	Bubble[6].anim.loop = false;
	Bubble[6].anim.speed = 0.11111f;
	Bubble[6].life = -1;
	Bubble[6].position.x = 143;
	Bubble[6].position.y = 190;

	// Grey Bubble particle
	Bubble[7].anim.PushBack({ 18, 583, 16, 16 });
	Bubble[7].anim.PushBack({ 35, 583, 16, 16 });
	Bubble[7].anim.PushBack({ 52, 583, 16, 16 });
	Bubble[7].anim.PushBack({ 69, 583, 16, 16 });
	Bubble[7].anim.PushBack({ 86, 583, 16, 16 });
	Bubble[7].anim.PushBack({ 103, 583, 16, 16 });
	Bubble[7].anim.PushBack({ 120, 583, 16, 16 });
	Bubble[7].anim.PushBack({ 137, 583, 16, 16 });
	Bubble[7].anim.PushBack({ 154, 583, 16, 16 });
	Bubble[7].anim.loop = false;
	Bubble[7].anim.speed = 0.11111f;
	Bubble[7].life = -1;
	Bubble[7].position.x = 143;
	Bubble[7].position.y = 190;
	
	// Purple Bubble particle
	Bubble[8].anim.PushBack({ 266, 631, 16, 16 });
	Bubble[8].anim.PushBack({ 283, 631, 16, 16 });
	Bubble[8].anim.PushBack({ 300, 631, 16, 16 });
	Bubble[8].anim.PushBack({ 317, 631, 16, 16 });
	Bubble[8].anim.PushBack({ 334, 631, 16, 16 });
	Bubble[8].anim.PushBack({ 351, 631, 16, 16 });
	Bubble[8].anim.PushBack({ 368, 631, 16, 16 });
	Bubble[8].anim.PushBack({ 385, 631, 16, 16 });
	Bubble[8].anim.PushBack({ 402, 631, 16, 16 });
	Bubble[8].anim.loop = false;
	Bubble[8].anim.speed = 0.11111f;
	Bubble[8].life = -1;
	Bubble[8].position.x = 143;
	Bubble[8].position.y = 190;


	point_rnd = App->player->rnd;
	
	sfx03 = Mix_LoadWAV("Resources/Audio/SFX/SFX 03.wav");

	LOG("Particle Loaded succsessfully");

	return true;
}

bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}
	LOG("Unloading sfx03 particles");
	if (sfx03 != nullptr){
//		Mix_FreeChunk(sfx03);
	}
	LOG("Unloading graphics particles");
App->textures->Unload(graphics);
LOG("Unloading particles");
	return true;
}

update_status ModuleParticles::Update()
{

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if(p == nullptr)
			continue;

		if(p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if(SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			if(p->fx_played == false)
			{
				p->fx_played = true;
				// Play particle fx here
			}
		}
	}

	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay)
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] == nullptr)
		{
			Particle* p = new Particle(particle);
			p->born = SDL_GetTicks() + delay;
			p->position.x = x;
			p->position.y = y;
			if (collider_type != COLLIDER_NONE)
				p->collider = App->collision->AddCollider({ p->position.x, p->position.y, 14, 14 }, collider_type, this);
			active[i] = p;

			p->speed.x = -cos(((float)App->player->player_angle) * M_PI / 180.f) * BUBBLE_SPEED;;
			p->speed.y = -sin(((float)App->player->player_angle) * M_PI / 180.f) * BUBBLE_SPEED;;

			break;
		}
	}
}

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) : 
anim(p.anim), position(p.position), speed(p.speed),
fx(p.fx), born(p.born), life(p.life)
{}

bool Particle::Update()
{
	bool ret = true;

	if(life > 0 || life == -1)
	{
		if((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if(anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	collider->SetPos(position.x + 1, position.y + 1);

	return ret;
}

void look_around_fall(){

	for (int j = 0; j < 8; j++)
		if (App->particles->board_copy[App->particles->ceiling_pos][j] == 420)
			App->particles->board_copy[App->particles->ceiling_pos][j] = 360;

	for (int i = App->particles->ceiling_pos + 1; i < 12 - 1; i++){

		for (int j = 0; j < 8; j++){


			if (i % 2 == 0){
				for (int k = j; k <= j + 1 && k < 8; k++)
					if (App->particles->board_copy[i - 1][k] == 360 && App->particles->board_copy[i][j] != E)
						App->particles->board_copy[i][j] = 360;
			}

			else {
				for (int k = j - 1; k <= j && k >= 0; k++)
					if (App->particles->board_copy[i - 1][k] == 360 && App->particles->board_copy[i][j] != E)
						App->particles->board_copy[i][j] = 360;
				
			}
		}

		for (int j = 0; j < 8; j++){

		
				for (int k = j - 1; k <= j + 1; k++)
					if (k >= 0 && k <= 7 && App->particles->board_copy[i][k] == 360 && App->particles->board_copy[i][j] != E)
						App->particles->board_copy[i][j] = 360;
		
		}
	}
}

int chain_fall(){

	int total_coll = 0;

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 8; j++)
			App->particles->board_copy[i][j] = E;

	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 8; j++)
			if (App->scene_1to3->bubble_board[i][j] != E)
				App->particles->board_copy[i][j] = 420;
	}

	// for (int i = 0; i < 12; i++)
	look_around_fall();


	total_coll = 0;

	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 8; j++)
			if (App->particles->board_copy[i][j] == 420)
				total_coll++;


	//"Popping" bubbles
		
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 8; j++)
			if (App->particles->board_copy[i][j] == 420){
				App->scene_1to3->bubble_board[i][j] = E;
				App->particles->board_copy[i][j] = E;
			}



	return total_coll;

}


bool look_around(int y, int x){

	bool done2;
	int cj = 420;
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 8; j++){
			if (App->particles->board_copy[i][j] == 420){
				y = i;
				x = j;
				App->particles->board_copy[i][j] = App->player->rnd;
				cj = j;
				break;
			}
		}

		if (App->particles->board_copy[i][cj] == App->player->rnd && x == cj && y == i)
			break;
	}


	for (int i = y + 1; i >= y - 1 && i >= 0; i--){

		if (i == y){

			for (int j = x - 1; j <= x + 1 && j >= 0; j++){

				if (j >= 0 && j <= 7 && App->scene_1to3->bubble_board[i][j] == App->player->rnd && App->particles->board_copy[i][j] == E){

					App->particles->board_copy[i][j] = 420;
				}
			}
		}

		else{
			if (i % 2 != 0){
				for (int j = x; j <= x + 1 && j <= 7; j++){

					if (j <= 7 && App->scene_1to3->bubble_board[i][j] == App->player->rnd && App->particles->board_copy[i][j] == E){

						App->particles->board_copy[i][j] = 420;
					}
				}
			}

			else {

				for (int j = x - 1; j <= x && j >= 0; j++){

					if (j >= 0 && App->scene_1to3->bubble_board[i][j] == App->player->rnd && App->particles->board_copy[i][j] == E){

						App->particles->board_copy[i][j] = 420;
					}
				}
			}
		}
	}


	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 8; j++){
			if (App->particles->board_copy[i][j] == 420)
				return false;
			else
				done2 = true;
		}
	}

	return done2;

}


int chain(int y, int x_ODD, int x_PAIR){ //chain returns the total amount of collisions
	while (true){
		if (y > 11)
			y /= 2;

		if (x_ODD > 7)
			x_ODD = 7;

		if (x_ODD < 1)
			x_ODD = 1;

		if (x_PAIR > 7)
			x_PAIR = 7;

			else break;
		}

		bool done = false;
		int total_coll = 0;

		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 8; j++)
				App->particles->board_copy[i][j] = E;

		if (y % 2 != 0){

			App->scene_1to3->bubble_board[y][x_ODD] = App->player->rnd;
			App->particles->board_copy[y][x_ODD] = App->player->rnd;
			while (done == false)
				done = look_around(y, x_ODD);

		}


		else{

			App->scene_1to3->bubble_board[y][x_PAIR] = App->player->rnd;
			App->particles->board_copy[y][x_PAIR] = App->player->rnd;
			while (done == false)
				done = look_around(y, x_PAIR);

		}

		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 8; j++)
				if (App->particles->board_copy[i][j] == App->player->rnd)
					total_coll++;


		//"Popping" bubbles
		if (total_coll <= 2)
			total_coll = 0;
		else
			for (int i = 0; i < 12; i++)
				for (int j = 0; j < 8; j++)
					if (App->particles->board_copy[i][j] == App->player->rnd)
						App->scene_1to3->bubble_board[i][j] = E;

		return total_coll;
	}


void ModuleParticles::OnCollision(Collider* c1, Collider* c2) {
	LOG("\nparticle col\n");


	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			if (c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_WALL){
				active[i]->speed.x *= -1;

				//sfx 03 is played when a bubble collides with a wall
				Mix_PlayChannel(-1, sfx03, 0);
			}

			if (c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_CEILING || c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_BOBBLE) {
				Mix_PlayChannel(-1, sfx02, 0);
				
				App->player->score += 10 * chain((active[i]->position.y - BUBBLE_OFFSET_Y) / 16, (active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16, ((active[i]->position.x - BUBBLE_OFFSET_X_PAIR) / 16) - 1);

				App->player->score += 10 * (2 ^ chain_fall());
				App->player->rnd = 0;

				delete active[i];
				active[i] = nullptr;
			}
		}
	}
}