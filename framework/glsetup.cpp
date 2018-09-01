#include "glsetup.h"
#include "assetloader.h"
#include "log.h"
#include <GL/glew.h>
#include <string>

namespace framework
{
	namespace render
	{
		GLuint tileShaderProg = 0;
		
		void registerTileShaders()
		{
			std::string tileVertSource;
			std::string tileFragSource;
			framework::asset::loadTextFile(&tileVertSource, "assets/shaders/opengl/tile.vert");
			framework::asset::loadTextFile(&tileFragSource, "assets/shaders/opengl/tile.frag");
			if (tileVertSource.length() == 0 || tileFragSource.length() == 0)
			{
				framework::logMessage("Could not compile tile shaders because the source code could not be loaded!", LOGLEVEL_ERROR);
				return;
			}

			GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
			const char* vs = tileVertSource.c_str();
			glShaderSource(vertShader, 1, &vs, NULL);
			glCompileShader(vertShader);
			char log[512] = {};
			GLsizei vertLogSize = 0;
			glGetShaderInfoLog(vertShader, 512, &vertLogSize, log);
			if (vertLogSize != 0)
			{
				std::string err;
				err.append("Error compiling tile.vert: ");
				err.append(log);
				framework::logMessage(err.c_str(), LOGLEVEL_ERROR);
			}

			GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
			const char* fs = tileFragSource.c_str();
			glShaderSource(fragShader, 1, &fs, NULL);
			glCompileShader(fragShader);
			GLsizei fragLogSize = 0;
			glGetShaderInfoLog(fragShader, 512, &fragLogSize, log);
			if (fragLogSize != 0)
			{
				std::string err;
				err.append("Error compiling tile.frag: ");
				err.append(log);
				framework::logMessage(err.c_str(), LOGLEVEL_ERROR);
			}

			tileShaderProg = glCreateProgram();
			glAttachShader(tileShaderProg, vertShader);
			glAttachShader(tileShaderProg, fragShader);
			glLinkProgram(tileShaderProg);
			glDeleteShader(vertShader);
			glDeleteShader(fragShader);
			glUseProgram(tileShaderProg);
		}

		void initShaders()
		{
			registerTileShaders();
		}
	}
}