#include "Graphics.h"

US_CV_FRAMEWORK


HRESULT Graphics::WinProc ( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
}

Graphics::Graphics()
{
}


Graphics::Graphics ( HINSTANCE hInstance, LPCSTR className, int width, int height, int fps, int isFullScreen )
{
	_hInstance = hInstance;
	_windowClassName = className;

	_isFullScreen = isFullScreen;

	_width = width;
	_height = height;

	_fps = fps;
}

void Graphics::initWindow ( )
{
}

int Graphics::isFullScreen ( ) const
{
	return _isFullScreen;
}

int Graphics::getWidth ( ) const
{
	return _width;
}

int Graphics::getHeight ( ) const
{
	return _height;
}

int Graphics::getFrameRate ( ) const
{
	return _fps;
}

HWND Graphics::getWindow ( ) const
{
	return _hWnd;
}

HINSTANCE Graphics::getInstance ( ) const
{
	return _hInstance;
}

Graphics::~Graphics()
{
}
