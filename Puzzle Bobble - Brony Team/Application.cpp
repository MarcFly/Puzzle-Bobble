#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
#include "PuzzleBubble\ModuleScene1-3.h"
#include "PuzzleBubble\ModuleScene4-6.h"
#include "PuzzleBubble\ModuleSceneGameOver.h"
#include "PuzzleBubble/ModuleSceneMainMenu.h"
#include "PuzzleBubble/ModuleParticles.h"
#include "PuzzleBubble\ModuleFadeToBlack.h"
#include "PuzzleBubble\ModuleAudio.h"
#include "ModuleCollision.h"
#include "ModuleEnemies.h"

Application::Application()
{
	int i = 0;
	modules[i++] = window = new ModuleWindow();
	modules[i++] = render = new ModuleRender();
	modules[i++] = input = new ModuleInput();
	modules[i++] = textures = new ModuleTextures();
	modules[i++] = scene_mainmenu = new ModuleSceneMainMenu();
	modules[i++] = scene_1to3 = new ModuleScene1to3();
	modules[i++] = scene_4to6 = new ModuleScene4to6();
	modules[i++] = scene_gameover = new ModuleSceneGameOver();
	modules[i++] = player = new ModulePlayer();
	modules[i++] = particles = new ModuleParticles();
	modules[i++] = enemies = new ModuleEnemies();
	modules[i++] = fade = new ModuleFadeToBlack();
	modules[i++] = collision = new ModuleCollision();
	modules[i++] = audio = new ModuleAudio();
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	player->Disable();
	scene_1to3->Disable();
	scene_4to6->Disable();
	scene_gameover->Disable();
	collision->Disable();
	particles->Disable();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}