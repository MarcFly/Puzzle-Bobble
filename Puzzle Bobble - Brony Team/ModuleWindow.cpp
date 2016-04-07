#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleWindow.h"

#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#pragma comment( lib, "SDL_image/libx86/SDL2_image.lib" )

ModuleWindow::ModuleWindow() : Module()
{
}


ModuleWindow::~ModuleWindow()
{
}


bool ModuleWindow::Init()
{
	LOG("Init SDL window & surface");
	bool ret = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG("SDL_VIDEO could not initialize! SDL_Error:\n");
		LOG(SDL_GetError());
		ret = false;
	}
	else
	{

		int width = SCREEN_WIDTH * SCREEN_SIZE;
		int height = SCREEN_HEIGHT * SCREEN_SIZE;
		Uint32 flags = SDL_WINDOW_SHOWN;

		if(WIN_FULLSCREEN == true)
			flags |= SDL_WINDOW_FULLSCREEN;

		if(WIN_BORDERLESS == true)
			flags |= SDL_WINDOW_BORDERLESS;

		if(WIN_RESIZABLE == true)
			flags |= SDL_WINDOW_RESIZABLE;

		if(WIN_FULLSCREEN_DESKTOP == true)
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;

		window = SDL_CreateWindow("", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		if(window == NULL)
		{
			LOG("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			ret = false;
		}
		else
		{

			screen_surface = SDL_GetWindowSurface(window);
		}
	}

	return ret;
}


bool ModuleWindow::CleanUp()
{
	LOG("Destroying SDL window and quitting all SDL systems");


	if(window != NULL)
		SDL_DestroyWindow(window);


	SDL_Quit();
	return true;
}

bool ModuleTextures::Unload(SDL_Texture* texture)
{
	bool ret = false;

	for (uint i = 0; i < MAX_TEXTURES; ++i)
	{
		if (texture == textures[i])
		{
			SDL_DestroyTexture(textures[i]);
			textures[i] = nullptr;
			ret = true;
			break;
		}
	}

	return ret;
}

