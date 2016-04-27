#ifndef __MODULEPARTICLES_H__
#define __MODULEPARTICLES_H__

#include "../Module.h"
#include "../Animation.h"
#include "../Globals.h"
#include "../p2Point.h"
#include "../ModuleCollision.h"
#include "ModuleAudio.h"
#include "../ModulePlayer.h"

#define MAX_ACTIVE_PARTICLES 1

struct SDL_Texture;

struct Particle
{
	bubble_color color;
	Collider* collider;
	Animation anim;
	uint fx = 0;
	fPoint position;
	fPoint speed;
	Uint32 born = 0;
	Uint32 life = 0;
	bool fx_played = false;

	Particle();
	Particle(const Particle& p);
	bool Update();
};

class ModuleParticles : public Module
{
public:
	ModuleParticles();
	~ModuleParticles();

	bool Start();
	update_status Update();
	bool CleanUp();

	void AddParticle(const Particle& particle, int x, int y, COLLIDER_TYPE collider_type, Uint32 delay = 0);
	void OnCollision(Collider*, Collider*);

private:

	SDL_Texture* graphics = nullptr;
	
	uint last_particle = 0;

public:

	//According to the Enemies we have so 0 to No Type, 1 to Blue, 2 to Red,...
	Particle Bubble[9];
	int point_rnd;

	Particle* active[MAX_ACTIVE_PARTICLES];

	//sound fx
	Mix_Chunk* sfx03 = nullptr;

};

#endif // __MODULEPARTICLES_H__