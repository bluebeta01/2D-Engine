#include "framework.h"
#include "win32_window.h"

namespace framework
{
	void Init(void(*initCallback)(), void(*renderCallback)(), void(*updateCallback)())
	{
		framework::render::InitWindow(initCallback, renderCallback, updateCallback);
	}
	void Init(void* windowHandle)
	{
		framework::render::InitWindow(windowHandle);
	}
}