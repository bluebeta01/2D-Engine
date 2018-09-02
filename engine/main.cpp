#include "framework.h"
#include "c_game.h"

Game* game;

void init() { game->Init(); }
void update() { game->Update(); }
void render() { game->Render(); }

int main()
{
	game = new Game();
	framework::Init(&init, &render, &update);
	delete game;
}