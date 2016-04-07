
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

	foreground.x = 88;
	foreground.y = 23;
	foreground.w = 145;
	foreground.h = 201;

	background.x = 9;
	background.y = 9;
	background.w = 310;
	background.h = 240;

}

ModuleScene1to3::~ModuleScene1to3()
{}

bool ModuleScene1to3::Start()
{
	LOG("Loading 1-3 scene");

	background_graphics = App->textures->Load("Sprites/Backgrounds/Background 1-3.png");
	foreground_graphics = App->textures->Load("Sprites/Backgrounds/Borders 1-3.png");

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

	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);

	App->render->Blit(foreground_graphics, 79, 14, &foreground, 0.92f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(this, (Module*)App->scene_4to6);
	}

	return UPDATE_CONTINUE;
}