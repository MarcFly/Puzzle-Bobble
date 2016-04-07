
#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "../ModuleInput.h"
#include "ModuleSceneMainMenu.h"
#include "../ModulePlayer.h"
#include "ModuleFadeToBlack.h"


ModuleSceneMainMenu::ModuleSceneMainMenu()
{
	background.x = 9;
	background.y = 9;
	background.w = 310;
	background.h = 240;

}

ModuleSceneMainMenu::~ModuleSceneMainMenu()
{}

bool ModuleSceneMainMenu::Start()
{
	LOG("Loading Main Menu scene");

	background_graphics = App->textures->Load("Sprites/MainScreen.png");

	return true;
}

// UnLoad assets
bool ModuleSceneMainMenu::CleanUp()
{
	LOG("Unloading Main Menu scene");
	App->player->Disable();

	return true;
}

update_status ModuleSceneMainMenu::Update()
{

	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(this, (Module*)App->scene_1to3);
	}

	return UPDATE_CONTINUE;
}