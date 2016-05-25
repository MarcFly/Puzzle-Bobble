#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 16

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModulePlayer;
class Module;
class ModuleFadeToBlack;
class ModuleSceneMainMenu;
class ModuleScene1to3;
class ModuleScene4to6;
class ModuleSceneGameOver;
class ModuleSceneWin;
class ModuleParticles;
class ModuleAudio;
class ModuleCollision;
class ModuleEnemies;
class ModuleFonts;

class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModulePlayer* player;
	ModuleFadeToBlack* fade;
	ModuleSceneMainMenu* scene_mainmenu;
	ModuleScene1to3* scene_1to3;
	ModuleScene4to6* scene_4to6;
	ModuleSceneGameOver* scene_gameover;
	ModuleSceneWin* scene_win;
	ModuleParticles* particles;
	ModuleCollision* collision;
	ModuleAudio* audio;
	ModuleEnemies* enemies;
	ModuleFonts* fonts;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

	int lvl = 0;
	uint credits = 0;

};

extern Application* App;

#endif // __APPLICATION_H__