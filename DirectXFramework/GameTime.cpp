#include "Definitions.h"
#include "GameTime.h"

US_CV_FRAMEWORK

GameTime::~GameTime ( )
{
}

void GameTime::release ( )
{
}

GameTime* GameTime::getInstance ( )
{
	if (_instance != NULL)
	{
		_instance = new GameTime();
	}
	return _instance;
}

void GameTime::init ( )
{
	_startTick = 0;
	_lastTick = 0;
	_currentTick = 0;

	QueryPerformanceFrequency(&_query);
	_frequencyQuery = float(_query.QuadPart) / 10000000;

	QueryPerformanceCounter(&_query);
	_lastTick = _query.QuadPart;
	_startTick = _lastTick;
	_totalGameTime = (TimeSpan)0;
}

void GameTime::resetLastTick ( )
{
	_lastTick = 0;
	_currentTick = 0;
	_totalGameTime = (TimeSpan)0;
}

void GameTime::updateGameTime ( )
{
	QueryPerformanceCounter(&_query);

	_currentTick = _query.QuadPart;

	_elapsedGameTime = float(_currentTick - _lastTick) / _frequencyQuery;


	_totalGameTime = _totalGameTime + _elapsedGameTime;

	_lastTick = _currentTick;
}

float GameTime::getElapsedGameTime ( ) const
{
	return _elapsedGameTime.getMillisecond (  );
}

float GameTime::getTotalGameTime ( ) const
{
	return _totalGameTime.getMillisecond();
}

GameTime::GameTime ( )
{
}
