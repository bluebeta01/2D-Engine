#pragma once

namespace framework
{
	namespace render
	{
		void InitWindow(void(*initCallback)(), void(*renderCallback)(), void(*updateCallback)());
		void swapBuffers();
	}
}