#pragma once
#include "framework.h"
#include <vector>

class TextureManager
{
public:
	TextureManager();
	void LoadAllTextures();
	void GetTextureByName(framework::render::Texture*&, const char*);

private:
	std::vector<framework::render::Texture*> textureRegistry;
};