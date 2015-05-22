#include "c_svm.h"
#include "cTest.h"
#include "c_core.h"
int  tolua_ClientTolua_open (lua_State* tolua_S);
int main()
{
	CoreSysInit();
	tolua_ClientTolua_open(CLuaSVM::GetSingleton().mLS);
	Example *ex  = new Example();
	CLuaSVM::GetSingleton().SetGlobalValue(arg1,1);
	CLuaSVM::GetSingleton().SetGlobalValue(arg2,"sandynie");
	int ret= luaL_dofile(CLuaSVM::GetSingleton().mLS, "test.lua"); 
	if (ret !=0)
	{
		printf("Error occurs when calling luaL_dofile() Hint Machine 0x%x\n",ret);
		printf("Error: %s", lua_tostring(CLuaSVM::GetSingleton().mLS,-1));
	}else{
		printf("Right!");
	}
	CLuaSVM::GetSingleton().ExecuteString("print (\"mama\")");
	CLuaSVM::GetSingleton().ExecuteFile("test.lua");
	char * ptest = "local jj=6;function boji()print(\"就是这么人性 \"..jj);end";
	int status = luaL_loadbuffer( CLuaSVM::GetSingleton().mLS, ptest, strlen(ptest), "" );
	if( status == 0 ) 
	{
		status = lua_pcall(  CLuaSVM::GetSingleton().mLS, 0, 0, 0 );
		if (status!=0)
		{
			printf( "error: %s\n", lua_tostring(CLuaSVM::GetSingleton().mLS, -1));
		}
	}
	CLuaSVM::GetSingleton().ExecuteScriptFileFunc("testfunc.lua","boji",NULL);
	system("pause");
	delete ex;
	CoreSysRelease();
	return 0;
}

/*
在UI中可以如下使用

int UIObject::CallScript(int type, const char * arg)
{

lua_getglobal(CLuaSVM::GetInstance()->mLS, "this");//backup pre this;
lua_getglobal(CLuaSVM::GetInstance()->mLS, GetName());
lua_setglobal(CLuaSVM::GetInstance()->mLS, "this");

int Ret = CLuaSVM::GetInstance().ExecuteString(m_pScriptStr[type].AsCharPtr());

lua_setglobal(CLuaSVM::GetInstance()->mLS, "this");
return Ret;
}


*/