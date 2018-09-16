#pragma once

namespace framework
{
	namespace render
	{
		void InitWindow(void(*initCallback)(), void(*renderCallback)(), void(*updateCallback)());
		void InitWindow(void* windowHandle);
		void swapBuffers();
	}
}