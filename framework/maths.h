#pragma once

namespace framework
{
	namespace math
	{
		struct matrix4f
		{
			float data[16] = {1, 0, 0, 0,   0, 1, 0, 0,   0, 0, 1, 0,   0, 0, 0, 1};

			static matrix4f orthoMatrix(float left, float right, float top, float bottom, float far, float near)
			{
				matrix4f mat;
				mat.data[0] = 2.0f / (right - left);
				mat.data[5] = 2.0f / (top - bottom);
				mat.data[10] = 2.0f / (near - far);
				mat.data[12] = (right + left) / (left - right);
				mat.data[13] = (top + bottom) / (bottom - top);
				mat.data[14] = (far + near) / (far - near);
				return mat;
			}
		};
	}
}