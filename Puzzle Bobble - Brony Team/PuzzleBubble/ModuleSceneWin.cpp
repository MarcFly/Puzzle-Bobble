#include "ModuleSceneWin.h"
#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "../ModuleInput.h"
#include "../ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "../ModuleCollision.h"
#include "ModuleParticles.h"
#include "../ModuleCollision.h"
#include "ModuleAudio.h"


ModuleSceneWin::ModuleSceneWin()
{
	background.x = 489;
	background.y = 1392;
	background.w = 111;
	background.h = 32;

}

ModuleSceneWin::~ModuleSceneWin()
{}

bool ModuleSceneWin::Start()
{
	LOG("Loading Win scene");

	background_graphics = App->textures->Load("Resources/Sprites/Game Sprites.png");

	Mix_PlayMusic(App->audio->music07, -1);

	return true;
}

// UnLoad assets
bool ModuleSceneWin::CleanUp()
{
	LOG("Unloading GameOver scene");
	App->textures->Unload(background_graphics);
	//App->player->Disable();

	return true;
}

update_status ModuleSceneWin::Update()
{

	App->render->Blit(background_graphics, 95, 90, &background, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN) {
		App->fade->FadeToBlack(this, (Module*)App->scene_mainmenu);
	}

	return UPDATE_CONTINUE;
}