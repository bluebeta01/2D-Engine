#include "spriterenderer.h"
#include "glsetup.h"
#include "win32_window.h"
#include "GL/glew.h"
#include "maths.h"
#include "log.h"
#include "texture.h"
#include <vector>
#include <string>

namespace framework
{
	namespace render
	{
		GLuint vao;
		GLuint vbo;
		std::vector<float> verts;
		Texture* texture = NULL;

		float zoomFactor = 50.0f;

		void initSpriteRenderer()
		{
			glGenVertexArrays(1, &vao);
			glBindVertexArray(vao);
			glGenBuffers(1, &vbo);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
		}

		void setTexture(Texture* texture)
		{
			framework::render::texture = texture;
			glBindTexture(GL_TEXTURE_2D, texture->glid);
		}

		void beginDraw()
		{
			glClearColor(0.0, 0.5, 1.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			verts.clear();
		}

		void drawSprite(math::Rect position, math::Rect uvs)
		{
			if (!texture)
			{
				logMessage("drawSprite() was called but there is no texture set in the sprite renderer!", LOGLEVEL_ERROR);
				return;
			}

			verts.push_back(position.x);
			verts.push_back(position.y);
			verts.push_back(uvs.x);
			verts.push_back(uvs.y);

			verts.push_back(position.x);
			verts.push_back(position.y + position.dy);
			verts.push_back(uvs.x);
			verts.push_back(uvs.dy);

			verts.push_back(position.x + position.dx);
			verts.push_back(position.y + position.dy);
			verts.push_back(uvs.dx);
			verts.push_back(uvs.dy);

			verts.push_back(position.x + position.dx);
			verts.push_back(position.y);
			verts.push_back(uvs.dx);
			verts.push_back(uvs.y);
		}

		void endDraw()
		{
			glBindVertexArray(vao);
			glBindBuffer(GL_ARRAY_BUFFER, vbo);
			glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verts.size(), verts.data(), GL_STREAM_DRAW);
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(sizeof(float) * 2));
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			
			glUseProgram(tileShaderProg);
			glUniformMatrix4fv(glGetUniformLocation(tileShaderProg, "projMat"), 1, false, framework::math::Matrix4f::orthoMatrix(0, 1280 / zoomFactor, 0, 720 / zoomFactor, 100, 0.1).data);
			glDrawArrays(GL_QUADS, 0, verts.size() / 4);

			swapBuffers();
		}
	}
}