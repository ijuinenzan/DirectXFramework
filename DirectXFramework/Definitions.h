#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#define _USE_MATH_DEFINES

#include <d3d9.h>
#include <d3dx9.h>

#include <windows.h>
#include <exception>
#include <math.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 448
#define SCALE_FACTOR 2.0f

#ifndef SAFE_DELETE

#define SAFE_DELETE(p) \
if(p) \
{\
	delete (p); \
	p = nullptr; \
} \

#endif // !SAFE_DELETE

typedef D3DXVECTOR3 GVector3;
typedef D3DXVECTOR2 GVector2;
#define VECTOR2ZERO GVector2(0.0f, 0.0f)
#define VECTOR2ONE  GVector2(1.0f, 1.0f)

#define NS_CV_FRAMEWORK		namespace FrameWork

#define NS_CV_FRAMEWORK_BEGIN	{

#define NS_CV_FRAMEWORK_END	}

#define US_CV_FRAMEWORK		using namespace FrameWork;

#endif
