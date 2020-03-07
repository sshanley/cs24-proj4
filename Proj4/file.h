#ifndef FILE_H
#define FILE_H
#include <string>

//Sean Shanley, 3/7/2020
class File{

	std::string file_name;
	int count;

	public:

	     File() {file_name = "", count = -1;}
	     File(std::string name);
	     std::string getFile();
	     int getCount();
	     void addCount(int x);

	     

};


#endif



