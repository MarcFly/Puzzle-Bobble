#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	// idle animation (arcade sprite sheet)
	idle.PushBack({16, 17, 18, 19});
	idle.PushBack({49, 17, 18, 19});
	idle.PushBack({84, 17, 18, 19});
	idle.PushBack({118, 17, 22, 19 });
	idle.PushBack({152, 17, 22, 19 });
	idle.PushBack({185, 17, 22, 19 });
	idle.PushBack({218, 17, 22, 19 });
	idle.PushBack({ 254, 17, 22, 19 });
	idle.PushBack({ 288, 17, 22, 19 });
	idle.speed = 0.05f;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Game Sprites.png");
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);
	
	return UPDATE_CONTINUE;
}