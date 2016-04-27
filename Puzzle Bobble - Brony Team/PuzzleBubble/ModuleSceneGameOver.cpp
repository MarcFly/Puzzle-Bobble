#include "ModuleSceneGameOver.h"
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


ModuleSceneGameOver::ModuleSceneGameOver()
{
	background.x = 9;
	background.y = 9;
	background.w = 310;
	background.h = 235;

}

ModuleSceneGameOver::~ModuleSceneGameOver()
{}

bool ModuleSceneGameOver::Start()
{
	LOG("Loading GameOver scene");

	background_graphics = App->textures->Load("Sprites/gameoverscene.png");

	return true;
}

// UnLoad assets
bool ModuleSceneGameOver::CleanUp()
{
	LOG("Unloading GameOver scene");
//	App->textures->Unload(background_graphics);
	App->player->Disable();

	return true;
}

update_status ModuleSceneGameOver::Update()
{

	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN) {
		return UPDATE_STOP;
	}

	return UPDATE_CONTINUE;
}