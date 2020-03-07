#include "file.h"
#include <iostream>

//Sean Shanley, 3/7/2020

File::File(std::string name)
{
	file_name = name;
	count = 1;
}

std::string File::getFile()
{
	return file_name;
}

int File::getCount()
{
	return count;
}

void File::addCount(int x)
{
	count+=x;
}
