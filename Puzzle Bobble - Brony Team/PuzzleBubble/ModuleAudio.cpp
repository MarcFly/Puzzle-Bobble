#include "../Globals.h"
#include "../Application.h"
#include "../ModuleInput.h"
#include "ModuleAudio.h"


#include "SDL_mixer/include/SDL_mixer.h"



ModuleAudio::ModuleAudio()
{
	music02 = nullptr;
	music03 = nullptr;
}

ModuleAudio::~ModuleAudio()
{}

bool ModuleAudio::Start()
{
	LOG("Loading music 02 and music 03");

	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, AUDIO_U8, 2, 1024);
	music02 = Mix_LoadMUS("../../Audio/MUSIC/MUSIC_02.ogg");
	music03 = Mix_LoadMUS("../../Audio/MUSIC/MUSIC_03.ogg");

	sfx01 = Mix_LoadWAV("../../Audio/SFX/SFX 01.wav");
	Mix_PlayMusic(music02, 1);

	return true;
}

bool ModuleAudio::CleanUp()
{
	LOG("Unloading intro scene");

	Mix_FreeMusic(music02);
	Mix_FreeMusic(music03);
	Mix_FreeChunk(sfx01);

	Mix_CloseAudio();
	Mix_Quit();

	return true;
}

update_status ModuleAudio::Update()
{
	if (App->input->keyboard[SDL_SCANCODE_SPACE]) {
		Mix_PlayMusic(music03, -1);
	}

	//if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) {
	//	Mix_PlayChannel(-1, sfx01, 0);
	//}
	return UPDATE_CONTINUE;
}

