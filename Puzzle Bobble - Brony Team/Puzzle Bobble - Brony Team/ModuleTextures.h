#ifndef	_MODULE_TEXTURES_H_
#define	_MODULE_TEXTURES_H_

#include "Include.h"
#include "Globals.h"

class ModuleTextures : public Module {
public:
	ModuleTextures();
	~ModuleTextures();

	bool Init();
	bool CleanUp();

	SDL_Texture* Load(const char* path);

public:
	SDL_Texture* textures[MAX_TEXTURES];
	unsigned int last_texture = 0;

};

#endif