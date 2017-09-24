#ifndef __TIME_SPAN_H__
#define __TIME_SPAN_H__
#include "Definitions.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class TimeSpan
{
public:
	static const UINT64 TicksPerSecond = 10000000;
	static const UINT64 TicksPerMillisecond = 10000;

	TimeSpan(void);
	TimeSpan(UINT64 ticks);

	float getMillisecond() const;
	UINT64 getTicks() const;

	~TimeSpan();

	TimeSpan operator+(TimeSpan timeSpan) const;
	TimeSpan operator+(UINT64) const;
private:
	UINT64 _ticks;
};
NS_CV_FRAMEWORK_END

#endif //__TIME_SPAN__