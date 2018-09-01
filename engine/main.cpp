#include "framework.h"
#include <iostream>
#include <string>

float x = 1.0f;

using namespace framework;
using namespace framework::render;

void Init()
{
	Texture t;
	t = Texture::read_png_file("assets/textures/tex.png");
	std::cout << t.width << std::endl;
}

void Update()
{

}

void Render()
{
	beginDraw();

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (x%2 == 0 || y%2 == 0)
			{
				drawSprite(x, y, 1, 1);
			}
		}
	}

	endDraw();
}

int main()
{
	Init(&Init, &Render, &Update);
}