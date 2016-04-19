#include <math.h>
#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "ModuleParticles.h"
#include "../ModulePlayer.h"

#define BUBBLE_SPEED 3.f

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

	// Red Bubble particle
	red_bubble.anim.PushBack({ 12, 312, 18, 16 });
	red_bubble.anim.PushBack({ 32, 312, 18, 16 });
	red_bubble.anim.PushBack({ 92, 312, 18, 16 });
	red_bubble.anim.PushBack({ 32, 312, 18, 16 });
	red_bubble.anim.PushBack({ 12, 312, 18, 16 });
	red_bubble.anim.loop = false;
	red_bubble.anim.speed = 0.2f;
	red_bubble.life = 1000; //it should be infinte but since it has no collisions we dont want to get a memory overflow
	red_bubble.position.x = 144;
	red_bubble.position.y = 175;

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
	
	red_bubble.speed.x = -cos(((float)App->player->player_angle) * M_PI / 180.f) * BUBBLE_SPEED;
	red_bubble.speed.y = -sin(((float)App->player->player_angle) * M_PI / 180.f) * BUBBLE_SPEED;

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

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, Uint32 delay)
{
	Particle* p = new Particle(particle);
	p->born = SDL_GetTicks() + delay;
	p->position.x = x;
	p->position.y = y;

	active[last_particle++] = p;
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

	if(life > 0)
	{
		if((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if(anim.Finished())
			ret = false;

	position.x += speed.x;
	position.y += speed.y;

	return ret;
}