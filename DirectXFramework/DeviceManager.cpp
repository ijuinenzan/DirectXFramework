#include "DeviceManager.h"

US_CV_FRAMEWORK

DeviceManager::DeviceManager()
{
	_pD3d = NULL;
	_pDevice = NULL;
	_surface = NULL;
}


DeviceManager::~DeviceManager()
{
	if(_pD3d != NULL)
	{
		_pD3d->Release();
	}

	if(_pDevice != NULL)
	{
		_pDevice->Release();
	}

	if(_surface != NULL)
	{
		_surface->Release();
	}
}

DeviceManager* DeviceManager::getInstance ( )
{
	if(!_instance)
	{
		_instance = new DeviceManager();
	}
	return _instance;
}

void DeviceManager::release ( )
{
}

void DeviceManager::clearScreen ( ) const
{
	_pDevice->ColorFill(_surface, NULL, D3DCOLOR_XRGB(0,0,0));
}

void DeviceManager::present ( ) const
{
	_pDevice->Present(0, 0, 0, 0);
}

void DeviceManager::init ( Graphics windows )
{
	_pD3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = !windows.isFullScreen (  );
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferWidth = windows.getWidth();
	d3dpp.BackBufferHeight = windows.getHeight();

	_pD3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		windows.getWindow(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&_pDevice);

	if (_pDevice == NULL) 
	{
		throw new exception("Can not create device !");
	}

	_pDevice->GetBackBuffer(NULL, NULL, D3DBACKBUFFER_TYPE_MONO, &_surface);
}

LPDIRECT3DDEVICE9 DeviceManager::getDevice ( ) const
{
	return _pDevice;
}

LPDIRECT3DSURFACE9 DeviceManager::getSurface ( ) const
{
	return _surface;
}
