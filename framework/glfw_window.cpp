#include "glfw_window.h"
#include "glsetup.h"
#include "spriterenderer.h"
#include <GLFW/glfw3.h>
#include <GL/glew.h>

namespace framework
{
	GLFWwindow* window;

	void InitWindow(void(*initCallback)(), void(*renderCallback)(), void(*updateCallback)())
	{

		/* Initialize the library */
		if (!glfwInit())
			return;

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(1280, 720, "Game", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		glewInit();
		framework::render::initShaders();
		framework::render::initSpriteRenderer();
		initCallback();

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			

			updateCallback();
			renderCallback();

			
		}

		glfwTerminate();
		return;
	}
}