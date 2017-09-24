#include <windows.h>
#include "Graphics.h"

US_CV_FRAMEWORK


HRESULT Graphics::WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}

Graphics::Graphics()
{
}


Graphics::Graphics(HINSTANCE hInstance, LPCSTR className, int width, int height, int fps, int isFullScreen)
{
	_hInstance = hInstance;
	_windowClassName = className;

	_isFullScreen = isFullScreen;

	_width = width;
	_height = height;

	_fps = fps;
}

void Graphics::initWindow()
{
	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = _hInstance;

	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _windowClassName;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	HWND hWnd =
		CreateWindow(
			_windowClassName,	// Window class name
			_windowClassName,	// Title  
			WS_OVERLAPPEDWINDOW, 		// Window type
			CW_USEDEFAULT,			// Initial position
			CW_USEDEFAULT,
			_width,				// Width
			_height,				// Height
			NULL,
			NULL,
			_hInstance,			// Program instance
			NULL);

	if (!hWnd) {
		throw new exception("Can't create window.");
	};

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

int Graphics::isFullScreen() const
{
	return _isFullScreen;
}

int Graphics::getWidth() const
{
	return _width;
}

int Graphics::getHeight() const
{
	return _height;
}

int Graphics::getFrameRate() const
{
	return _fps;
}

HWND Graphics::getWindow() const
{
	return _hWnd;
}

HINSTANCE Graphics::getInstance() const
{
	return _hInstance;
}

Graphics::~Graphics()
{
}
