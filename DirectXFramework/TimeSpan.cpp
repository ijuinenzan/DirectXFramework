#include "TimeSpan.h"

US_CV_FRAMEWORK

TimeSpan::TimeSpan ( )
{
}

TimeSpan::TimeSpan ( UINT64 ticks )
{
	_ticks = ticks;
}

float TimeSpan::getMillisecond ( ) const
{
	return _ticks / TicksPerMillisecond;
}

UINT64 TimeSpan::getTicks ( ) const
{
	return _ticks;
}

TimeSpan TimeSpan::operator+ ( TimeSpan timeSpan ) const
{
	return TimeSpan(this->_ticks + timeSpan._ticks);
}

TimeSpan TimeSpan::operator+ ( UINT64 ticks ) const
{
	return TimeSpan(this->_ticks + ticks);
}


TimeSpan::~TimeSpan()
{
}
