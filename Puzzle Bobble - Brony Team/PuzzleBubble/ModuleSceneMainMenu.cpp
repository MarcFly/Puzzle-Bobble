
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
	background.h = 230;

	UI.PushBack({ 72, 154, 173, 22 });
	UI.PushBack({ 0, 0, 0, 0 });
	UI.speed = 0.02f;

}

ModuleSceneMainMenu::~ModuleSceneMainMenu()
{}

bool ModuleSceneMainMenu::Start()
{
	LOG("Loading Main Menu scene");

	background_graphics = App->textures->Load("Sprites/MainScreen.png");
	UI_graphics = App->textures->Load("Sprites/UIMainScreen.png");

	return true;
}

bool ModuleSceneMainMenu::CleanUp()
{
	LOG("Unloading Main Menu scene");
	App->player->Disable();

	return true;
}

update_status ModuleSceneMainMenu::Update()
{

	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);

	App->render->Blit(UI_graphics, 60, 150, &(UI.GetCurrentFrame()), 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(this, (Module*)App->scene_1to3);
	}

	return UPDATE_CONTINUE;
}