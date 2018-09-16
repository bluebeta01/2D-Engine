#pragma once
#include "c_texturemanager.h"

class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	void Render();

	TextureManager* pTextureManager;
};