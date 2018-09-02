#pragma once
#include "c_texturemanager.h"

class RenderManager
{
public:
	RenderManager();
	void Render();

	TextureManager* pTextureManager;
};