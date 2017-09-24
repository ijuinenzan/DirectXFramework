#include "Definitions.h"
#include "GameTime.h"

US_CV_FRAMEWORK

pGameTime GameTime::_instance = NULL;

GameTime::~GameTime()
{
}

void GameTime::release()
{
	SAFE_DELETE(_instance);
}

GameTime* GameTime::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new GameTime;
	}

	return _instance;
}

void GameTime::init()
{
	QueryPerformanceFrequency(&_query);

	this->_frequencyQuery = float(_query.QuadPart) / 10000000;

	QueryPerformanceCounter(&_query);
	_startTick = _query.QuadPart;
	_lastTick = _query.QuadPart;

	_totalGameTime = TimeSpan(0);
}

void GameTime::resetLastTick()
{
	_lastTick = 0;
	_currentTick = 0;
	_totalGameTime = TimeSpan(0);
}

void GameTime::updateGameTime()
{
	QueryPerformanceCounter(&_query);
	_currentTick = _query.QuadPart;

	if (UINT64(float(_currentTick - _lastTick) / _frequencyQuery)   <  TimeSpan::TicksPerMillisecond * 16)
	{
		return;
	}

	auto gt = float(_currentTick - _lastTick) / _frequencyQuery;
	_totalGameTime = _totalGameTime + gt;
	_elapsedGameTime = TimeSpan(UINT64(gt));
	_lastTick = _currentTick;
}

float GameTime::getElapsedGameTime() const
{
	return _elapsedGameTime.getMillisecond();
}

float GameTime::getTotalGameTime() const
{
	return _totalGameTime.getMillisecond();
}

GameTime::GameTime()
{
}
