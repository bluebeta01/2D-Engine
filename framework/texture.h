#pragma once
#pragma warning (disable : 4996)
#include <png.h>
#include <iostream>
#include "maths.h"

namespace framework
{
	namespace render
	{
		struct Texture
		{
			int width, height;
			unsigned int glid;

			static framework::math::Rect tileUvsFromTexture(Texture* tex, int tileX, int tileY)
			{
				float sx = (float)tileX / (float)(tex->width / 16);
				float sy = (float)tileY / (float)(tex->height / 16);
				float ex = (float)(tileX + 1.0f) / (float)(tex->width / 16);
				float ey = (float)(tileY + 1.0f) / (float)(tex->height / 16);
				framework::math::Rect rect(sx, sy, ex, ey);
				return rect;
			}
		};
	}
}