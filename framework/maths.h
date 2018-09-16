#pragma once

namespace framework
{
	namespace math
	{
		struct Matrix4f
		{
			float data[16] = {1, 0, 0, 0,   0, 1, 0, 0,   0, 0, 1, 0,   0, 0, 0, 1};

			static Matrix4f orthoMatrix(float left, float right, float top, float bottom, float farView, float nearView)
			{
				Matrix4f mat;
				mat.data[0] = 2.0f / (right - left);
				mat.data[5] = 2.0f / (top - bottom);
				mat.data[10] = 2.0f / (nearView - farView);
				mat.data[12] = (right + left) / (left - right);
				mat.data[13] = (top + bottom) / (bottom - top);
				mat.data[14] = (farView + nearView) / (farView - nearView);
				return mat;
			}
		};

		struct Rect
		{
			Rect() {}

			Rect(float x, float y, float dx, float dy)
			{
				this->x = x;
				this->y = y;
				this->dx = dx;
				this->dy = dy;
			}
			float x, y, dx, dy;
		};
	}
}