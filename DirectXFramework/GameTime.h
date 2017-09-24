#ifndef __GAME_TIME_H__
#define __GAME_TIME_H__

#include "Definitions.h"
#include "TimeSpan.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class GameTime
{
public:
	~GameTime(void);

	static void release();
	static GameTime* getInstance();
	void init();
	void resetLastTick();
	void updateGameTime();

	float getElapsedGameTime() const;
	float getTotalGameTime() const;
private:
	static GameTime *_instance;
	TimeSpan _elapsedGameTime;
	TimeSpan _totalGameTime;

	LARGE_INTEGER _query;

	float _frequencyQuery;

	LONGLONG _startTick;
	LONGLONG _lastTick;
	LONGLONG _currentTick;

	GameTime(void);
};
typedef GameTime* pGameTime;

NS_CV_FRAMEWORK_END

#endif //__GAME_TIME_H__
