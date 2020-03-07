#ifndef WORD_H
#define WORD_H
#include "file.h"
#include "dnode.h"
#include <string>
#include <cstddef>

#define DEFAULT 100


//Sean Shanley, 3/7/2020 

class Word{
	private:
	  std::string word;
	   int count;
	   dnode<File>* files_head;
	   dnode<File>* files_tail;


	   public:
	   Word() {word = "", count = -1, files_head = NULL; files_tail = NULL;} 
	   Word(std::string name); // constructor
	   void clear(); //need to make destructor
	   std::string getWord();
	   int getCount();
	   void addCount(int x);
	   void addFile(std::string file);
	   dnode<File>* hasFile(std::string name);
	   std::string print_word();
	   void print_files_thresh(int thresh);
	   dnode<File>* getHead();	  	
};


#endif



