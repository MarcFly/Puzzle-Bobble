#ifndef	_MODULE_RENDER_H_
#define	_MODULE_RENDER_H_

#include "Include.h"

class ModuleRender : public Module {
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PostUpdate();
	update_status PreUpdate();
	bool CleanUp();

public:
	SDL_Renderer* render;
	SDL_Texture* texture;

};

#endif