#include "win32_window.h"
#include "glsetup.h"
#include "spriterenderer.h"
#include "log.h"
#include <GL/glew.h>
#include <GL/wglew.h>
#include <Windows.h>

namespace framework
{
	namespace render
	{
		HINSTANCE hInstance;
		HWND hwnd;
		HDC hdc;
		MSG msg;
		HGLRC openglInstance;
		bool running = true;

		void swapBuffers()
		{
			SwapBuffers(hdc);
		}

		LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
		{
			switch (message)
			{
			case WM_CLOSE:
			{
				wglMakeCurrent(hdc, NULL);
				wglDeleteContext(openglInstance);
				running = false;
				PostQuitMessage(0);
				break;
			}
			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
			return 0;

		}

		void createOpenglContext()
		{
			hdc = GetDC(hwnd);
			PIXELFORMATDESCRIPTOR pfd = {};
			ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

			pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
			pfd.nVersion = 1;
			pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
			pfd.iPixelType = PFD_TYPE_RGBA;
			pfd.cColorBits = 32;
			pfd.cDepthBits = 24;
			pfd.cStencilBits = 8;
			pfd.iLayerType = PFD_MAIN_PLANE;

			//Types = Teal; Functions = Blue; Constants = Purple

			//Set the pixel format of the window's device context
			int windowPixelFormat = ChoosePixelFormat(hdc, &pfd);
			if (windowPixelFormat == 0)
			{
				logMessage("Could not find a valid pixel format!", LOGLEVEL_ERROR);
				return;
			}
			SetPixelFormat(hdc, windowPixelFormat, &pfd);

			//Create the opengl context and store it in openglInstance
			openglInstance = wglCreateContext(hdc);
			wglMakeCurrent(hdc, openglInstance);

			glewInit();

			const int contextAttribs[] =
			{
				WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
				WGL_CONTEXT_MINOR_VERSION_ARB, 0,
				WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB,
				WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
				0, // End
			};
			wglMakeCurrent(hdc, NULL);
			wglDeleteContext(openglInstance);
			openglInstance = wglCreateContextAttribsARB(hdc, NULL, contextAttribs);
			wglMakeCurrent(hdc, openglInstance);

			wglSwapIntervalEXT(1);
		}

		void InitWindow(void(*initCallback)(), void(*renderCallback)(), void(*updateCallback)())
		{
			hInstance = GetModuleHandle(NULL);

			WNDCLASS wc = { 0 };
			wc.lpfnWndProc = WndProc;
			wc.hInstance = hInstance;
			wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
			wc.lpszClassName = "oglversionchecksample";
			wc.style = CS_OWNDC;
			if (!RegisterClass(&wc))
			{
				logMessage("Could not register window class!", LOGLEVEL_ERROR);
				return;
			}
			RECT wr = { 0, 0, 1280, 720 };
			hwnd = CreateWindow(wc.lpszClassName, "OpenGL 2D Engine", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top, 0, 0, hInstance, 0);

			createOpenglContext();

			framework::render::initShaders();
			framework::render::initSpriteRenderer();
			initCallback();

			while (running)
			{
				PeekMessage(&msg, NULL, 0, 0, true);
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				updateCallback();

				//Render code
				{
					renderCallback();
				}
			}

			return;
		}

		void InitWindow(void* windowHandle)
		{
			hInstance = GetModuleHandle(NULL);
			hwnd = (HWND)windowHandle;

			createOpenglContext();

			framework::render::initShaders();
			framework::render::initSpriteRenderer();
		}
	}
}