#pragma once
#include <Windows.h>

extern bool isEditorRunning;

LRESULT CALLBACK EditorProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);