#include "c_filestream.h"
#include <fstream>
using std::ifstream;
using std::ofstream;
using std::fstream;


int File_Stream::Read(string path, char *dataptr, int numBytes)
{
	return Read(path.c_str(),dataptr,numBytes);
}
int File_Stream::Read(const char* path, char *dataptr, int numBytes)
{
	if (numBytes > 0 )
	{
		ifstream is(path);
		while (is.good() && !is.eof())
		{
			is.read(dataptr,numBytes);
		}
		is.close();
	}
	return 0;
}

int File_Stream::Write(const char* path,char * dataptr,int numBytes)
{
	if (numBytes > 0 )
	{
		ofstream os(path);
		if (os.is_open())
		{
			os.write(dataptr,numBytes);
		}
		os.close();
	}
	return 0;
}

long File_Stream::GetSize(const char* path)
{
	ifstream is(path);
	if (is.good())
	{
		is.seekg(0,is.end);
		return is.tellg();
	}
}