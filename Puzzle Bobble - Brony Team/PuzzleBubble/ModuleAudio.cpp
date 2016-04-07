#include "../Globals.h"
#include "../Application.h"
#include "ModuleAudio.h"


#include "SDL_mixer/include/SDL_mixer.h"



ModuleAudio::ModuleAudio()
{
	music03 = nullptr;
}

ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Start()
{
	LOG("Loading music 03");

	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_U8, 2, 1024);
	music03 = Mix_LoadMUS("../../Audio/MUSIC/MUSIC_03.ogg");
	Mix_PlayMusic(music03, -1);

	return true;
}

bool ModuleAudio::CleanUp()
{
	LOG("Unloading intro scene");

	Mix_FreeMusic(music03);

	Mix_CloseAudio();
	Mix_Quit();

	return true;
}

update_status ModuleAudio::Update()
{

	return UPDATE_CONTINUE;
}

