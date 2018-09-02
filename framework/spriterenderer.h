#pragma once
#include "maths.h"
#include "texture.h"

namespace framework
{
	namespace render
	{
		extern float zoomFactor;

		void initSpriteRenderer();
		void setTexture(Texture* texture);
		void beginDraw();
		void drawSprite(math::Rect position, math::Rect uvs);
		void endDraw();

		
	}
}