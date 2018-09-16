#include "framework.h"
#include "c_game.h"
#include "editor/c_editor.h"
#include "log.h"
#include <string>

bool launchArgsContain(const char* arg, int argCount, char* args[]);

bool isEditor = false;
Game* game;
Editor* editor;

void init() { game->Init(); }
void update() { game->Update(); }
void render() { game->Render(); }

int main(int argc, char* args[])
{
	if (!launchArgsContain("-devmode", argc, args))
	{
		game = new Game();
		framework::Init(&init, &render, &update);
		delete game;
	}
	else
	{
		editor = new Editor();
		delete editor;
	}
}



bool launchArgsContain(const char* arg, int argCount, char* args[])
{
	for (int i = 0; i < argCount; i++)
	{
		std::string s = args[i];
		if (s == arg)
			return true;
	}
	return false;
}