
#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "../ModuleInput.h"
#include "ModuleScene4-6.h"
#include "../ModulePlayer.h"
#include "ModuleFadeToBlack.h"
#include "../ModuleCollision.h"
#include "ModuleParticles.h"
#include "../ModuleCollision.h"


ModuleScene4to6::ModuleScene4to6()
{
	foreground.x = 88;
	foreground.y = 23;
	foreground.w = 145;
	foreground.h = 201;

	background.x = 9;
	background.y = 9;
	background.w = 310;
	background.h = 235;

	limit_line.x = 34;
	limit_line.y = 1688;
	limit_line.w = 127;
	limit_line.h = 4;
}

ModuleScene4to6::~ModuleScene4to6()
{}

bool ModuleScene4to6::Start()
{
	LOG("Loading 4-6 scene");

	background_graphics = App->textures->Load("Resources/Sprites/Backgrounds/Background 4-6.png");
	foreground_graphics = App->textures->Load("Resources/Sprites/Backgrounds/Borders 4-6.png");
	game_sprites_graphics = App->textures->Load("Resources/Sprites/Game Sprites.png");

	App->player->Enable();
	App->particles->Enable();
	App->collision->Enable();
	App->enemies->Enable();

	App->collision->AddCollider({ 78, 15, 9, 215 }, COLLIDER_WALL);
	App->collision->AddCollider({ 78, 15, 145, 8 }, COLLIDER_CEILING);
	App->collision->AddCollider({ 215, 15, 8, 215 }, COLLIDER_WALL);

	//App->collision->AddCollider({ 86, 184, 129, 4 }, COLLIDER_PLAYER);

	return true;
}

// UnLoad assets
bool ModuleScene4to6::CleanUp()
{
	LOG("Unloading 4-6 scene");
	App->textures->Unload(background_graphics);
	App->textures->Unload(foreground_graphics);
	App->player->Disable();
	App->collision->Disable();
	App->particles->Disable();
	App->enemies->Disable();

	return true;
}

update_status ModuleScene4to6::Update()
{

	App->render->Blit(background_graphics, 0, 0, &background, 0.75f);

	App->render->Blit(game_sprites_graphics, 87, 184, &limit_line, 1.f);

	App->render->Blit(foreground_graphics, 79, 14, &foreground, 0.92f);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		App->fade->FadeToBlack(this, (Module*)App->scene_1to3);
	}

	return UPDATE_CONTINUE;
}