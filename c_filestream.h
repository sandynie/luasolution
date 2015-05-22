#ifndef _C_IOSTREAM_H
#define _C_IOSTREAM_H
#include <string>
using std::string;
class File_Stream{
public:
	static int Read(const char* path,char *dataptr, int numBytes);
	static int Read(string path,char *dataptr, int numBytes);
	static int Write(const char* path,char *dataptr, int numBytes);
	static long GetSize(const char* path);
};
#endif