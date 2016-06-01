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
	background.x = 213;
	background.y = 179;
	background.w = 213;
	background.h = 63;

}

ModuleSceneWin::~ModuleSceneWin()
{}

bool ModuleSceneWin::Start()
{
	LOG("Loading Win scene");

	App->input->Enable();

	background_graphics = App->textures->Load("Resources/Sprites/congratsscreen.png");

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

	App->render->Blit(background_graphics, 43, 70, &background, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN) {
		App->fade->FadeToBlack(this, (Module*)App->scene_mainmenu, FADE_SPEED);
	}

	return UPDATE_CONTINUE;
}