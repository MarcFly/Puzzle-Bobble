
#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "../ModuleInput.h"
#include "ModuleScene4-6.h"
#include "../ModulePlayer.h"
#include "ModuleFadeToBlack.h"


ModuleScene4to6::ModuleScene4to6()
{
	foreground.x = 88;
	foreground.y = 23;
	foreground.w = 155;
	foreground.h = 201;

	background.x = 9;
	background.y = 9;
	background.w = 310;
	background.h = 240;

}

ModuleScene4to6::~ModuleScene4to6()
{}

bool ModuleScene4to6::Start()
{
	LOG("Loading 4-6 scene");

	background_graphics = App->textures->Load("Sprites/Backgrounds/Background 4-6.png");
	foreground_graphics = App->textures->Load("Sprites/Backgrounds/Borders 4-6.png");

	App->player->Enable();

	return true;
}

// UnLoad assets
bool ModuleScene4to6::CleanUp()
{
	LOG("Unloading 4-6 scene");
	App->player->Disable();

	return true;
}

update_status ModuleScene4to6::Update()
{

	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);

	App->render->Blit(foreground_graphics, 79, 14, &foreground, 0.92f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(this, (Module*)App->scene_1to3);
	}

	return UPDATE_CONTINUE;
}