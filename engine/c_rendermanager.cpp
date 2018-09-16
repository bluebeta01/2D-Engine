#include "c_rendermanager.h"
#include "log.h"
#include "frame_counter.h"

using namespace framework::render;
using namespace framework::math;

RenderManager::RenderManager()
{
	pTextureManager = new TextureManager();
	pTextureManager->LoadAllTextures();
}

RenderManager::~RenderManager()
{
	delete pTextureManager;
}

void RenderManager::Render()
{
	beginDraw();

	Texture* spriteSheet;
	pTextureManager->GetTextureByName(spriteSheet, "");

	if (!spriteSheet)
		logMessage("Spritesheet texture is null", LOGLEVEL_DEBUG);
	setTexture(spriteSheet);

	drawSprite(Rect(0, 0, 1, 1), Texture::tileUvsFromTexture(spriteSheet, 0, 0));

	endDraw();
	calcDelta();
}