#include "glfw_window.h"
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
		initCallback();

		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT);

			updateCallback();
			renderCallback();
			glClearColor(0.0, 0.5, 1.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
		return;
	}
}