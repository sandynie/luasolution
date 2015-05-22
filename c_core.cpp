#include "c_core.h"
static bool s_bInit = false;
int CoreSysInit()
{
	if(s_bInit)
	{
		return 0;
	}
	s_bInit = true;

	pLua = new CLuaSVM();
	pLua->mbShutScript = false;
	if(pLua == NULL)
		return -1;
	return 0;
}
int CoreSysRelease()
{
 if (pLua!=NULL)
 {
	 delete pLua;
 }
 s_bInit = false;
 return 0;
}