#pragma once

namespace framework
{
	namespace render
	{
		extern float zoomFactor;

		void initSpriteRenderer();
		void beginDraw();
		void drawSprite(float x, float y, float width, float height);
		void endDraw();

		
	}
}