
#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "../ModuleInput.h"
#include "ModuleSceneMainMenu.h"
#include "../ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include "stdio.h"


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

	font = App->fonts->Load("Resources/Sprites/stdWhiteFontCLEAN.png", " !@,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);

	timer_insert = 500;

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

	if (App->input->keyboard[SDL_SCANCODE_TAB] == KEY_DOWN)
		App->debug_mode = !App->debug_mode;


	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);
	
	if (App->debug_mode == true) {
		App->credits = 99;
		App->fonts->Blit(2, 217, 0, "DEBUG_MODE");
	}

	if (App->credits > 0)
	App->render->Blit(UI_graphics, 60, 150, &(UI.GetCurrentFrame()), 0.75f);
	else {
		if (SDL_GetTicks() > timer_insert + 750) {
			show_insert = !show_insert;
			timer_insert = SDL_GetTicks();
		}
		if (show_insert)
			App->fonts->Blit(106, 155, 0, "INSERT_COIN");
	}
	sprintf_s(credits_text, 15, "CREDITS_%d", App->credits);
	App->fonts->Blit(220, 210, 0, credits_text);

	if (App->input->keyboard[SDL_SCANCODE_1] == 1 && App->credits > 0) {
		App->fade->FadeToBlack(this, (Module*)App->scene_1to3, FADE_SPEED);
		App->lvl = 1;
		App->player->score = 0;
		App->credits--;
	}

	if (App->input->keyboard[SDL_SCANCODE_C] == KEY_DOWN && App->credits < 99) {
		Mix_PlayChannel(-1, sfx08, 0);
		App->credits++;
	}

	return UPDATE_CONTINUE;
}