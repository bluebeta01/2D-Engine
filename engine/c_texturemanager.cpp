#include "c_texturemanager.h"
#include "log.h"

using namespace framework::render;
using namespace framework::asset;

TextureManager::TextureManager()
{

}

void TextureManager::LoadAllTextures()
{
	Texture* tex;
	loadTexture(tex, "assets/textures/tex.png");
	if (tex)
		textureRegistry.push_back(tex);
	else
	{
		logMessage("Texture is still null", LOGLEVEL_DEBUG);
	}
}

void TextureManager::GetTextureByName(framework::render::Texture*& texture, const char* name)
{
	texture = textureRegistry[0];
}