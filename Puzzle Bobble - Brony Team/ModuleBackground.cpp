#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

ModuleBackground::ModuleBackground()
{

	// Background rect
	background.x = 10;
	background.y = 10;
	background.w = 320;
	background.h = 240;
}

ModuleBackground::~ModuleBackground()
{}


bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Sprites/Backgrounds/Background 1-3.png");
	return ret;
}


update_status ModuleBackground::Update()
{
	App->render->Blit(graphics, 0, 0, &background, 0.75f);

	return UPDATE_CONTINUE;
}