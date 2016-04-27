#include "../Globals.h"
#include "../Application.h"
#include "../ModuleInput.h"
#include "ModuleAudio.h"


#include "SDL_mixer/include/SDL_mixer.h"



ModuleAudio::ModuleAudio()
{
	music02 = nullptr;
	music03 = nullptr;
	music05 = nullptr;
}

ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Start()
{
	LOG("Loading music");

	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 1024);
	music02 = Mix_LoadMUS("Resources/Audio/MUSIC/MUSIC_02.ogg");
	music03 = Mix_LoadMUS("Resources/Audio/MUSIC/MUSIC_03.ogg");
	music05 = Mix_LoadMUS("Resources/Audio/MUSIC/MUSIC_05.ogg");
	music07 = Mix_LoadMUS("Resources/Audio/MUSIC/MUSIC_07.ogg");

	return true;
}

bool ModuleAudio::CleanUp()
{
	LOG("Unloading intro scene");

	Mix_FreeMusic(music05);
	Mix_FreeMusic(music02);
	Mix_FreeMusic(music03);
	Mix_FreeMusic(music07);

	Mix_CloseAudio();
	Mix_Quit();

	return true;
}

update_status ModuleAudio::Update()
{

	return UPDATE_CONTINUE;
}

