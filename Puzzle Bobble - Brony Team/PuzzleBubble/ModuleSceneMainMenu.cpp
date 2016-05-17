
#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "../ModuleInput.h"
#include "ModuleSceneMainMenu.h"
#include "../ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"


ModuleSceneMainMenu::ModuleSceneMainMenu()
{
	background.x = 9;
	background.y = 9;
	background.w = 310;
	background.h = 225;

	UI.PushBack({ 72, 154, 173, 22 });
	UI.PushBack({ 0, 0, 0, 0 });
	UI.speed = 0.02f;

}

ModuleSceneMainMenu::~ModuleSceneMainMenu()
{}

bool ModuleSceneMainMenu::Start()
{
	LOG("Loading Main Menu scene");

	sfx08 = nullptr;

	background_graphics = App->textures->Load("Resources/Sprites/MainScreen.png");
	graphics = App->textures->Load("Resources/Sprites/Game Sprites.png");
	UI_graphics = App->textures->Load("Resources/Sprites/UIMainScreen.png");

	LOG("Loading music02");
	Mix_PlayMusic(App->audio->music02, 1);

	sfx08 = Mix_LoadWAV("Resources/Audio/SFX/SFX 08.wav");
	LOG("Scene MainMenu Started Succesfully");

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
		Mix_PlayChannel(-1, sfx08, 0);
		App->fade->FadeToBlack(this, (Module*)App->scene_1to3);
		App->lvl = 1;
	}

	return UPDATE_CONTINUE;
}