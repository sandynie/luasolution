#ifndef _C_CORE_H
#define _C_CORE_H
#include "c_svm.h"
static CLuaSVM * pLua = NULL;
int CoreSysInit();
 int CoreSysRelease();
#endif