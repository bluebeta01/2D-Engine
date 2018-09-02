#include "c_game.h"

Game::Game()
{
	
}

void Game::Init()
{
	pRenderManager = new RenderManager();
}

void Game::Update()
{

}

void Game::Render()
{
	pRenderManager->Render();
}