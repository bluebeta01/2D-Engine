#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace framework
{
	extern GLFWwindow* window;

	void InitWindow(void(*initCallback)(), void(*renderCallback)(), void(*updateCallback)());
}