#ifndef __MODULESCENE4TO6_H__
#define __MODULESCENE4TO6_H__

#include "../Module.h"
#include "../Animation.h"

struct SDL_Texture;

class ModuleScene4to6 : public Module {
public:
	ModuleScene4to6();
	~ModuleScene4to6();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* background_graphics = nullptr;
	SDL_Texture* foreground_graphics = nullptr;
	SDL_Texture* game_sprites_graphics = nullptr;
	SDL_Rect foreground;
	SDL_Rect background;
	SDL_Rect limit_line;
	SDL_Rect level_info;

};

#endif 