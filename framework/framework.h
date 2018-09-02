#pragma once
#define GLEW_STATIC
#include "assetloader.h"
#include "spriterenderer.h"
#include "texture.h"
#include "maths.h"

namespace framework
{
	void Init(void(*initCallback)(), void(*renderCallback)(), void(*updateCallback)());
}