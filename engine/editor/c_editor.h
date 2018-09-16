#pragma once
#include <Windows.h>
#include "../c_rendermanager.h"

class Editor
{
public:
	HWND hwnd;
	HINSTANCE hInstance;
	RenderManager* pRenderManager;


	Editor();
	~Editor();
	void init();
	void update();
	void render();
};