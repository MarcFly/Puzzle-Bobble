#ifndef __MODULESCENEMAINMENU_H__
#define __MODULESCENEMAINMENU_H__

#include "../Module.h"
#include "../Animation.h"
#include "../Globals.h"
#include "ModuleAudio.h"

struct SDL_Texture;

class ModuleSceneMainMenu : public Module {
public:
	ModuleSceneMainMenu();
	~ModuleSceneMainMenu();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* background_graphics = nullptr;
	SDL_Texture* UI_graphics = nullptr;
	SDL_Rect background;
	Animation UI;
	int font = -1;
	char credits_text[15];

	Mix_Chunk* sfx08 = nullptr;
	
};

#endif 