#pragma once
#include <string>
#include "texture.h"

namespace framework
{
	namespace asset
	{
		void loadTextFile(std::string* text, const char* path);
		void loadTexture(framework::render::Texture*& texture, const char* path);
	}
}