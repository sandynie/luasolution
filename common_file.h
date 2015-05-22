#ifndef _COMMON_FILE_H
#define _COMMON_FILE_H
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include<memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <map>
#include <string>
#include <exception>
#include <time.h>
using std::exception;
using std::vector;
using std::string;
#define CC_SAFE_DELETE(p)            do { if(p) { delete (p); (p) = 0; } } while(0)
#define CC_SAFE_DELETE_ARRAY(p)     do { if(p) { delete[] (p); (p) = 0; } } while(0)
#define CC_SAFE_FREE(p)                do { if(p) { free(p); (p) = 0; } } while(0)
#define CC_SAFE_RELEASE(p)            do { if(p) { (p)->release(); } } while(0)
#define CC_SAFE_RELEASE_NULL(p)        do { if(p) { (p)->release(); (p) = 0; } } while(0)
#define CC_SAFE_RETAIN(p)            do { if(p) { (p)->retain(); } } while(0)
#define CC_BREAK_IF(cond)            if(cond) break
#define ToString( T ) #T
#define CCRANDOM_0_1() ((float)rand()/RAND_MAX)
#define CCAssert(cond, msg) do {                              \
	if (!(cond)) {                                          \
	if (strlen(msg)) \
	assert(cond);                                      \
	} \
} while (0)
	inline float  floorf( float _X)
	{
		return (float)(_X);
	}
#if defined(__BCPLUSPLUS__) || defined(_MSC_VER)
	typedef __int64 Int64;
#define T_INT64(n) n##i64;
#elif defined(TNET_64)
	typedef long Int64;
#define T_INT64(n) n##L;
#else
	typedef long long Int64;
#define T_INT64(n) n##LL
#endif
	typedef unsigned char Uint8;
	typedef unsigned char BYTE;
	typedef unsigned char Byte;
	typedef short Short;
	typedef int Int;
	typedef Int64 Long;
	typedef float Float;
	typedef double Double;
	typedef unsigned int uint32_t;
	typedef vector<bool> BoolSeq;
	typedef vector<Byte> ByteSeq;
	typedef vector<Short> ShortSeq;
	typedef vector<Int> IntSeq;
	typedef vector<Long> LongSeq;
	typedef vector<Float> FloatSeq;
	typedef vector<Double> DoubleSeq;
	typedef vector<string> StringSeq;
#endif