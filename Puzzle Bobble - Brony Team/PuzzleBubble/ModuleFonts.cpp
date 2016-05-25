#include "../Globals.h"
#include "../Application.h"
#include "../ModuleTextures.h"
#include "../ModuleRender.h"
#include "ModuleFonts.h"

#include<string.h>

// Constructor
ModuleFonts::ModuleFonts() : Module()
{}

// Destructor
ModuleFonts::~ModuleFonts()
{}

// Load new texture from file path
int ModuleFonts::Load(const char* texture_path, const char* characters, uint rows)
{
	int id = -1;

	if(texture_path == nullptr || characters == nullptr || rows == 0)
	{
		LOG("Could not load font");
		return id;
	}

	SDL_Texture* tex = App->textures->Load(texture_path);

	if(tex == nullptr || strlen(characters) >= MAX_FONT_CHARS)
	{
		LOG("Could not load font at %s with characters '%s'", texture_path, characters);
		return id;
	}

	id = 0;
	for(; id < MAX_FONTS; ++id)
		if(fonts[id].graphic == nullptr)
			break;

	if(id == MAX_FONTS)
	{
		LOG("Cannot load font %s. Array is full (max %d).", texture_path, MAX_FONTS);
		return id;
	}

	// TODO 1: Create a new font using "id" for the position in the array
	// graphic: pointer to the texture (loaded already)
	// table: array of chars to have the list of characters
	// rows: rows of characters in the texture
	// len: length of the table
	// row_chars: amount of chars per row of the texture
	// char_w: width of each character
	// char_h: height of each character
	for (int i = '!'; i < '~'; i++) {
		fonts[id].table[i - '!'] = i;
	}
	fonts[id].graphic = tex;
	fonts[id].rows = 3;
	fonts[id].len = 96;
	fonts[id].row_chars = 32;
	fonts[id].char_w = 8;
	fonts[id].char_h = 8;
	
	LOG("Successfully loaded BMP font from %s", texture_path);

	return id;
}

void ModuleFonts::UnLoad(int font_id)
{
	if(font_id >= 0 && font_id < MAX_FONTS && fonts[font_id].graphic != nullptr)
	{
		App->textures->Unload(fonts[font_id].graphic);
		fonts[font_id].graphic = nullptr;
		LOG("Successfully Unloaded BMP font_id %d", font_id);
	}
}

// Render text using a bmp font
void ModuleFonts::Blit(int x, int y, int font_id, const char* text) const
{
	if(text == nullptr || font_id < 0 || font_id >= MAX_FONTS || fonts[font_id].graphic == nullptr)
	{
		LOG("Unable to render text with bmp font id %d", font_id);
		return;
	}

	const Font* font = &fonts[font_id];
	SDL_Rect rect;
	uint len = strlen(text);

	rect.w = font->char_w;
	rect.h = font->char_h;

	for(uint i = 0; i < len; ++i)
	{
		// TODO 2: Find the character in the table and its position in the texture, then Blit
		for (uint k = 0; k < font->len; k++) {
			if (text[i] == font->table[k]){
				if (text[i] >= '0' && text[i] <= '9') {
					rect.x = 146 + (text[i] - '0') * (font->char_w + 1);
					rect.y = 2;
				}
				if (text[i] >= 'A' && text[i] <= 'Z') {
					rect.x = 2 + (text[i] - 'A') * (font->char_w + 1);
					rect.y = 11;
				}
				if (text[i] == '_') {
					rect.x = 1;
					rect.y = 1;
				}

				
			}
		}
			App->render->Blit(font->graphic, x, y, &rect);
			x += font->char_w;

	}

}
