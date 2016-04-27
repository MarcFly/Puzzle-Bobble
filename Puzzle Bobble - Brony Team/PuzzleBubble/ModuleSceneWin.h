#ifndef	__MODULESCENEWIN_H__
#define	__MODULESCENEWIN_H__

#include "../Module.h"
#include "../Application.h"


struct SDL_Texture;

class ModuleSceneWin : public Module {
public:
	ModuleSceneWin();
	~ModuleSceneWin();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background_graphics = nullptr;
	SDL_Rect background;

};


#endif