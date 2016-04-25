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
	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Sprites/Game Sprites.png");

	// Blue Bubble particle
	Bubble[1].anim.PushBack({ 12, 260, 18, 16 });
	Bubble[1].anim.PushBack({ 32, 260, 18, 16 });
	Bubble[1].anim.PushBack({ 52, 260, 18, 16 });
	Bubble[1].anim.PushBack({ 72, 260, 18, 16 });
	Bubble[1].anim.PushBack({ 92, 260, 18, 16 });
	Bubble[1].anim.PushBack({ 72, 260, 18, 16 });
	Bubble[1].anim.PushBack({ 52, 260, 18, 16 });
	Bubble[1].anim.PushBack({ 32, 260, 18, 16 });
	Bubble[1].anim.PushBack({ 12, 260, 18, 16 });
	Bubble[1].anim.loop = false;
	Bubble[1].anim.speed = 0.11111f;
	Bubble[1].life = -1;
	Bubble[1].position.x = 143;
	Bubble[1].position.y = 190;

	// Red Bubble particle
	Bubble[2].anim.PushBack({ 12, 312, 18, 16 });
	Bubble[2].anim.PushBack({ 32, 312, 18, 16 });
	Bubble[2].anim.PushBack({ 92, 312, 18, 16 });
	Bubble[2].anim.PushBack({ 32, 312, 18, 16 });
	Bubble[2].anim.PushBack({ 12, 312, 18, 16 });
	Bubble[2].anim.loop = false;
	Bubble[2].anim.speed = 0.2f;
	Bubble[2].life = -1;
	Bubble[2].position.x = 143;
	Bubble[2].position.y = 190;

	// Green Bubble particle
	Bubble[3].anim.PushBack({ 318, 260, 18, 16 });
	Bubble[3].anim.PushBack({ 338, 260, 18, 16 });
	Bubble[3].anim.PushBack({ 358, 260, 18, 16 });
	Bubble[3].anim.PushBack({ 378, 260, 18, 16 });
	Bubble[3].anim.PushBack({ 398, 260, 18, 16 });
	Bubble[3].anim.PushBack({ 378, 260, 18, 16 });
	Bubble[3].anim.PushBack({ 358, 260, 18, 16 });
	Bubble[3].anim.PushBack({ 338, 260, 18, 16 });
	Bubble[3].anim.PushBack({ 318, 260, 18, 16 });
	Bubble[3].anim.loop = false;
	Bubble[3].anim.speed = 0.11111f;
	Bubble[3].life = -1;
	Bubble[3].position.x = 143;
	Bubble[3].position.y = 190;

	// Yellow Bubble particle
	Bubble[4].anim.PushBack({ 12, 338, 18, 16 });
	Bubble[4].anim.PushBack({ 32, 338, 18, 16 });
	Bubble[4].anim.PushBack({ 52, 338, 18, 16 });
	Bubble[4].anim.PushBack({ 72, 338, 18, 16 });
	Bubble[4].anim.PushBack({ 92, 338, 18, 16 });
	Bubble[4].anim.PushBack({ 72, 338, 18, 16 });
	Bubble[4].anim.PushBack({ 52, 338, 18, 16 });
	Bubble[4].anim.PushBack({ 32, 338, 18, 16 });
	Bubble[4].anim.PushBack({ 12, 338, 18, 16 });
	Bubble[4].anim.loop = false;
	Bubble[4].anim.speed = 0.11111f;
	Bubble[4].life = -1;
	Bubble[4].position.x = 143;
	Bubble[4].position.y = 190;

	// Black Bubble particle
	Bubble[5].anim.PushBack({ 318, 286, 18, 16 });
	Bubble[5].anim.PushBack({ 338, 286, 18, 16 });
	Bubble[5].anim.PushBack({ 358, 286, 18, 16 });
	Bubble[5].anim.PushBack({ 378, 286, 18, 16 });
	Bubble[5].anim.PushBack({ 398, 286, 18, 16 });
	Bubble[5].anim.PushBack({ 378, 286, 18, 16 });
	Bubble[5].anim.PushBack({ 358, 286, 18, 16 });
	Bubble[5].anim.PushBack({ 338, 286, 18, 16 });
	Bubble[5].anim.PushBack({ 318, 286, 18, 16 });
	Bubble[5].anim.loop = false;
	Bubble[5].anim.speed = 0.11111f;
	Bubble[5].life = -1;
	Bubble[5].position.x = 143;
	Bubble[5].position.y = 190;

	// Orange Bubble particle
	Bubble[6].anim.PushBack({ 318, 312, 18, 16 });
	Bubble[6].anim.PushBack({ 338, 312, 18, 16 });
	Bubble[6].anim.PushBack({ 358, 312, 18, 16 });
	Bubble[6].anim.PushBack({ 378, 312, 18, 16 });
	Bubble[6].anim.PushBack({ 398, 312, 18, 16 });
	Bubble[6].anim.PushBack({ 378, 312, 18, 16 });
	Bubble[6].anim.PushBack({ 358, 312, 18, 16 });
	Bubble[6].anim.PushBack({ 338, 312, 18, 16 });
	Bubble[6].anim.PushBack({ 318, 312, 18, 16 });
	Bubble[6].anim.loop = false;
	Bubble[6].anim.speed = 0.11111f;
	Bubble[6].life = -1;
	Bubble[6].position.x = 143;
	Bubble[6].position.y = 190;

	// Grey Bubble particle
	Bubble[7].anim.PushBack({ 12, 286, 18, 16 });
	Bubble[7].anim.PushBack({ 32, 286, 18, 16 });
	Bubble[7].anim.PushBack({ 52, 286, 18, 16 });
	Bubble[7].anim.PushBack({ 72, 286, 18, 16 });
	Bubble[7].anim.PushBack({ 92, 286, 18, 16 });
	Bubble[7].anim.PushBack({ 72, 286, 18, 16 });
	Bubble[7].anim.PushBack({ 52, 286, 18, 16 });
	Bubble[7].anim.PushBack({ 32, 286, 18, 16 });
	Bubble[7].anim.PushBack({ 12, 286, 18, 16 });
	Bubble[7].anim.loop = false;
	Bubble[7].anim.speed = 0.11111f;
	Bubble[7].life = -1;
	Bubble[7].position.x = 143;
	Bubble[7].position.y = 190;
	
	// Purple Bubble particle
	Bubble[8].anim.PushBack({ 318, 338, 18, 16 });
	Bubble[8].anim.PushBack({ 338, 338, 18, 16 });
	Bubble[8].anim.PushBack({ 358, 338, 18, 16 });
	Bubble[8].anim.PushBack({ 378, 338, 18, 16 });
	Bubble[8].anim.PushBack({ 398, 338, 18, 16 });
	Bubble[8].anim.PushBack({ 378, 338, 18, 16 });
	Bubble[8].anim.PushBack({ 358, 338, 18, 16 });
	Bubble[8].anim.PushBack({ 338, 338, 18, 16 });
	Bubble[8].anim.PushBack({ 318, 338, 18, 16 });
	Bubble[8].anim.loop = false;
	Bubble[8].anim.speed = 0.11111f;
	Bubble[8].life = -1;
	Bubble[8].position.x = 143;
	Bubble[8].position.y = 190;

	return true;
}

bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for(uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if(active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

update_status ModuleParticles::Update()
{
	
	Bubble[2].speed.x = -cos(((float)App->player->player_angle) * M_PI / 180.f) * BUBBLE_SPEED;
	Bubble[2].speed.y = -sin(((float)App->player->player_angle) * M_PI / 180.f) * BUBBLE_SPEED;

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
				p->collider = App->collision->AddCollider({ p->position.x, p->position.y, 16, 16 }, collider_type, this);
			active[i] = p;
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

	collider->SetPos(position.x, position.y);

	return ret;
}

void ModuleParticles::OnCollision(Collider* c1, Collider* c2) {
	LOG("\nparticle col\n");
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr && active[i]->collider == c1)
		{
			if (c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_WALL){
				active[i]->speed.x *= -1;
			}

			if (c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_CEILING || c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_BOBBLE) {
				if ((int)active[i]->position.y % 2)
					App->scene_1to3->bubble_board[(((int)active[i]->position.y - BUBBLE_OFFSET_Y) / 15) - 1][(((int)active[i]->position.x - BUBBLE_OFFSET_X_PAIR) / 16) - 1] = R;
				else
					App->scene_1to3->bubble_board[(((int)active[i]->position.y - BUBBLE_OFFSET_Y) / 15) - 1][(((int)active[i]->position.x - BUBBLE_OFFSET_X_ODD) / 16) - 1] = R;
				
				App->collision->EraseCollider(active[i]->collider);

				delete active[i];
				active[i] = nullptr;
			}
		}
	}
}