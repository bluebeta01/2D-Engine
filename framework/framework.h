#pragma once
#include "assetloader.h"
#include "spriterenderer.h"
#include "texture.h"

namespace framework
{
	void Init(void(*initCallback)(), void(*renderCallback)(), void(*updateCallback)());
}