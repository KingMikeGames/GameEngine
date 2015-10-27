#pragma once

#define SNPRINTF snprintf

#define ZERO_MEM(a) memset(a,0,sizeof(a))
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define SAFE_DELETE(p) if(p) {delete p; p = NULL;}
#define INVALID_VALUE 0xFFFFFFFF

#define ToRadian(x) (float)(((x) * 3.1415926536f / 180.0f))
#define ToDegree(x) (float)(((x) * 180.0f / 3.1415926536f))

namespace Util {
	void sleep(int milliseconds);
};