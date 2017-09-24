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
}

void GameTime::init ( )
{
}

void GameTime::resetLastTick ( )
{
}

void GameTime::updateGameTime ( )
{
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
