#include "c_editor.h"
#include "win_proc.h"
#include "framework.h"

MSG msg;

Editor::Editor()
{
	init();
}

Editor::~Editor()
{
	delete pRenderManager;
}

void Editor::init()
{
	hInstance = GetModuleHandle(NULL);

	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = EditorProc;
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
	wc.lpszClassName = "editor";
	wc.style = CS_OWNDC;
	if (!RegisterClass(&wc))
	{
		return;
	}
	RECT wr = { 0, 0, 1280, 720 };
	HWND mainWindow = CreateWindow(wc.lpszClassName, "Level Editor", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top, 0, 0, hInstance, 0);

	CreateWindowEx(0, "button", "OK", WS_CHILD | WS_VISIBLE, 100, 100, 73, 23, mainWindow, NULL, hInstance, NULL);

	framework::Init((void*)mainWindow);

	pRenderManager = new RenderManager();
	pRenderManager->pTextureManager->LoadAllTextures();

	isEditorRunning = true;
	while (isEditorRunning)
	{

		if (PeekMessage(&msg, mainWindow, NULL, NULL, 1))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		update();
		render();

	}
}

void Editor::update()
{

}

void Editor::render()
{
	framework::render::beginDraw();
	framework::render::Texture* t;
	pRenderManager->pTextureManager->GetTextureByName(t, "");
	framework::render::setTexture(t);
	framework::render::drawSprite(framework::math::Rect(0, 0, 1, 1), framework::render::Texture::tileUvsFromTexture(t, 0, 0));
	framework::render::endDraw();
}