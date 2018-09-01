#include "assetloader.h"
#include "log.h"
#include <iostream>
#include <fstream>
#include <string>

namespace framework
{
	namespace asset
	{
		void loadTextFile(std::string* text, const char* path)
		{
			std::ifstream file;
			file.open(path);
			if (!file)
			{
				std::string err;
				err.append("Could not load text from file ");
				err.append(path);
				framework::logMessage(err.c_str(), LOGLEVEL_ERROR);
				return;
			}
			while (!file.eof())
			{
				char i = (char)file.get();
				if (i != -1)
				{
					text->push_back(i);
				}
			}
			file.close();
		}
	}
}