#ifndef __MODULEAUDIO_H_
#define __MODULEAUDIO_H_

#include "../Module.h"
#include "../Globals.h"
#include "SDL_mixer\include\SDL_mixer.h"

#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )



class ModuleAudio : public Module
{
public:
	ModuleAudio();
	~ModuleAudio();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	Mix_Music* music01 = nullptr;
	Mix_Music* music02 = nullptr;
	Mix_Music* music03 = nullptr;
	Mix_Music* music04 = nullptr;
	Mix_Music* music05 = nullptr;
	Mix_Music* music06 = nullptr;
	Mix_Music* music07 = nullptr;
	Mix_Music* music08 = nullptr;

	Mix_Chunk* sfx07 = nullptr;
};
#endif
