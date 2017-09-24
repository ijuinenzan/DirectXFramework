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
}

void DeviceManager::release ( )
{
}

void DeviceManager::clearScreen ( ) const
{
}

void DeviceManager::present ( ) const
{
}

void DeviceManager::init ( Graphics windows )
{
}

LPDIRECT3DDEVICE9 DeviceManager::getDevice ( ) const
{
}

LPDIRECT3DSURFACE9 DeviceManager::getSurface ( ) const
{
}
