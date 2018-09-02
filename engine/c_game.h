#pragma once
#include "c_rendermanager.h"

class Game
{
public:
	Game();
	void Init();
	void Update();
	void Render();

	RenderManager* pRenderManager;
private:
	
};