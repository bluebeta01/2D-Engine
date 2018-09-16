#include <Windows.h>
#include "win_proc.h"

bool isEditorRunning = false;

LRESULT CALLBACK EditorProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		isEditorRunning = false;
		break;
	}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}