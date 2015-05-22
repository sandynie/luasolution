#ifndef _CTEST_H
#define _CTEST_H
#include "common_file.h"
class Example { // tolua_export

private:

	string name;
	int number;

public:
	Example();
	void set_number(int number);

	//tolua_begin
	string get_name();
	int get_number();
	// tolua_end
};//tolua_export

#endif