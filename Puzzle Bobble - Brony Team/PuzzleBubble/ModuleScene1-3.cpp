
#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "../ModuleInput.h"
#include "ModuleScene1-3.h"
#include "../ModulePlayer.h"
#include "../ModuleFadeToBlack.h"


ModuleScene1to3::ModuleScene1to3()
{

	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	foreground.x = 8;
	foreground.y = 24;
	foreground.w = 521;
	foreground.h = 181;

	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	foreground_pos = 0;
}

ModuleScene1to3::~ModuleScene1to3()
{}

bool ModuleScene1to3::Start()
{
	LOG("Loading 1-3 scene");

	graphics = App->textures->Load("Sprites/Backgrounds/Background_1-3.png");

	App->player->Enable();

	return true;
}

// UnLoad assets
bool ModuleScene1to3::CleanUp()
{
	LOG("Unloading 1-3 scene");
	App->player->Disable();

	return true;
}

update_status ModuleScene1to3::Update()
{

	App->render->Blit(graphics, 0, 0, &background, 0.75f);

	App->render->Blit(graphics, 0, (int)foreground_pos, &foreground, 0.92f);

	App->render->Blit(graphics, 0, 170, &ground);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(this, (Module*)App->scene_4to6);
	}

	return UPDATE_CONTINUE;
}