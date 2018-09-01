#include "spriterenderer.h"
#include "glsetup.h"
#include "glfw_window.h"
#include "GL/glew.h"
#include "maths.h"
#include "log.h"
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

namespace framework
{
	namespace render
	{
		GLuint vao;
		GLuint vbo;
		std::vector<float> verts;
		float zoomFactor = 50.0f;

		void initSpriteRenderer()
		{
			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
		}

		void beginDraw()
		{
			glClearColor(0.0, 0.5, 1.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			verts.clear();
		}

		void drawSprite(float x, float y, float width, float height)
		{
			verts.push_back(x);
			verts.push_back(y);
			verts.push_back(x);
			verts.push_back(y + height);
			verts.push_back(x + width);
			verts.push_back(y + height);
			verts.push_back(x + width);
			verts.push_back(y);
		}

		void endDraw()
		{
			glBindVertexArray(vao);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verts.size(), verts.data(), GL_STATIC_DRAW);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			
			glUseProgram(tileShaderProg);
			glUniformMatrix4fv(glGetUniformLocation(tileShaderProg, "projMat"), 1, false, framework::math::matrix4f::orthoMatrix(0, 1280 / zoomFactor, 0, 720 / zoomFactor, 100, 0.1).data);
			glDrawArrays(GL_QUADS, 0, verts.size() / 2);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
}