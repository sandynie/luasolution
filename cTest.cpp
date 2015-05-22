#include "cTest.h"
#include "c_svm.h"
#include "tolua++.h"
Example::Example()
{
	number = 1234;
	const char * type = "Example";
	tolua_pushusertype(CLuaSVM::GetSingleton().mLS, (void*)this,  type);
	lua_setglobal(CLuaSVM::GetSingleton().mLS, "Example");
}
string Example::get_name()
{
	return name;
}

int Example::get_number()
{
	return number;
}

void Example::set_number(int inumber)
{
	this->number = inumber;
}

