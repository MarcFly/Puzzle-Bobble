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

#define BUBBLE_SPEED 3.3f

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

void ModuleParticles::OnCollision(Collider* c1, Collider* c2) {
	LOG("\nparticle col\n");

	int total_coll = 0;

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			

			if (c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_CEILING || c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_BOBBLE) {
				Mix_PlayChannel(-1, sfx02, 0);
				
				if ((int)(((active[i]->position.y - BUBBLE_OFFSET_Y) / 16)) % 2){
					if ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16)) > 0)
						if ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16)) == 7)
							App->scene_1to3->bubble_board[(int)(((active[i]->position.y - BUBBLE_OFFSET_Y) / 16))][(int)(((active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16))] = App->player->rnd;

						else if ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16)) == 0)
							App->scene_1to3->bubble_board[(int)(((active[i]->position.y - BUBBLE_OFFSET_Y) / 16))][(int)(((active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16) + 1)] = App->player->rnd;

						else
							App->scene_1to3->bubble_board[(int)(((active[i]->position.y - BUBBLE_OFFSET_Y) / 16))][(int)(((active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16))] = App->player->rnd;


					for (int y = ((int)(((active[i]->position.y - 8) / 16)) + 1); y >= ((int)(((active[i]->position.y - BUBBLE_OFFSET_Y) / 16)) - 1); y--){
					
						if (y == ((int)(((active[i]->position.y - 8) / 16)) + 1))
							for (int x = ((int)(((active[i]->position.x - 71) / 16))); x >= ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16)) - 1); x--){

								if (App->scene_1to3->bubble_board[y][x] == App->player->rnd)
									total_coll++;

							}

						else if (y == ((int)(((active[i]->position.y - 8) / 16)) - 1))
							for (int x = ((int)(((active[i]->position.x - 71) / 16))); x >= ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16)) - 1); x--){

								if (App->scene_1to3->bubble_board[y][x] == App->player->rnd)
									total_coll++;
	
							}
						else if (y == ((int)(((active[i]->position.y - 8) / 16))))
							for (int x = ((int)(((active[i]->position.x - 71) / 16)) + 1); x >= ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16)) - 1) && x != 0 && x <= 7; x--){

								if (App->scene_1to3->bubble_board[y][x] == App->player->rnd && x <= 7 )
									total_coll++;

							}

					}

					//CONTINUAR CADENA
 
					if (total_coll >= 2)
					for (int y = ((int)(((active[i]->position.y - 8) / 16)) + 1); y >= ((int)(((active[i]->position.y - BUBBLE_OFFSET_Y) / 16)) - 1); y--){
						for (int x = ((int)(((active[i]->position.x - 71) / 16)) + 1); x >= ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16)) - 1) && !(x == 0 && y == (int)(((active[i]->position.y - BUBBLE_OFFSET_Y) / 16))); x--){

							if (App->scene_1to3->bubble_board[y][x] == App->player->rnd)
								App->scene_1to3->bubble_board[y][x] = E;

						}
					}

				}

				else{


					App->scene_1to3->bubble_board[(int)(((active[i]->position.y - BUBBLE_OFFSET_Y) / 16))][(int)(((active[i]->position.x - BUBBLE_OFFSET_X_PAIR) / 16) - 1)] = App->player->rnd;

					for (int y = ((int)(((active[i]->position.y - 8) / 16)) + 1); y >= ((int)(((active[i]->position.y - BUBBLE_OFFSET_Y) / 16)) - 1); y--){

						if (y == ((int)(((active[i]->position.y - 8) / 16)) + 1))
							for (int x = ((int)(((active[i]->position.x - 64) / 16)) - 1); x <= ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_PAIR) / 16))); x++){

								if (App->scene_1to3->bubble_board[y][x] == App->player->rnd)
									total_coll++;

							}

						else if (y == ((int)(((active[i]->position.y - 8) / 16)) - 1))
							for (int x = ((int)(((active[i]->position.x - 64) / 16)) - 1); x <= ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_PAIR) / 16))); x++){

								if (App->scene_1to3->bubble_board[y][x] == App->player->rnd)
									total_coll++;

							}
						else if (y == ((int)(((active[i]->position.y - 8) / 16))))
							for (int x = ((int)(((active[i]->position.x - 64) / 16))); x >= ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_PAIR) / 16)) - 1); x--){

								if (App->scene_1to3->bubble_board[y][x] == App->player->rnd)
									total_coll++;

							}

					}

					//CONTINUAR CADENA

					if (total_coll >= 2)
					for (int y = ((int)(((active[i]->position.y - 8) / 16)) + 1); y >= ((int)(((active[i]->position.y - BUBBLE_OFFSET_Y) / 16)) - 1); y--){
						for (int x = ((int)(((active[i]->position.x - 71) / 16)) + 1); x >= ((int)(((active[i]->position.x - BUBBLE_OFFSET_X_PAIR) / 16)) - 1); x--){

							if (App->scene_1to3->bubble_board[y][x] == App->player->rnd)
								App->scene_1to3->bubble_board[y][x] = E;

						}
					}

				}

				active[i]->collider->to_delete = true;

				

				delete active[i];
				active[i] = nullptr;

				if (active[i] == nullptr)
					App->player->rnd = 0;
			}

			if (c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_WALL){
				active[i]->speed.x *= -1;

				//sfx 03 is played when a bubble collides with a wall
				Mix_PlayChannel(-1, sfx03, 0);
			}

		}
	}

	

}