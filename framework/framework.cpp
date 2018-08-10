#include "framework.h"
#include "glfw_window.h"

namespace framework
{
	void Init(void(*initCallback)(), void(*renderCallback)(), void(*updateCallback)())
	{
		InitWindow(initCallback, renderCallback, updateCallback);
	}
}