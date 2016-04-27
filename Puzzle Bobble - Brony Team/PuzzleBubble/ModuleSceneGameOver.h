#ifndef __MODULESCENEGAMEOVER_H__
#define	__MODULESCENEGAMEOVER_H__

#include "../Module.h"
#include "../Application.h"


struct SDL_Texture;

class ModuleSceneGameOver : public Module {
public:
	ModuleSceneGameOver();
	~ModuleSceneGameOver();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background_graphics = nullptr;
	SDL_Rect background;

};

#endif