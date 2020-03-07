#include <iostream>
#include "word.h"
//Sean Shanley, 3/7/2020
Word::Word(std::string name)
{
	word = name;
	count = 0;
	files_head = NULL;
	files_tail = NULL;

}

void Word::clear()
{
	dnode<File>* traverse = files_head;
	dnode<File>* temp = traverse;
	while (traverse)
	{

		traverse = traverse -> getNext();

		if (temp)
		{
			delete temp;
			
		}

		temp = traverse;

	}
	count = 0;
	files_head = NULL;
	files_tail = NULL;
	
}

std::string Word::getWord()
{
	return word;
}

int Word::getCount()
{
	return count;
}

void Word::addCount(int x)
{
	count += x;
}

void Word::addFile(std::string file)
{
	dnode<File>* file_ptr = hasFile(file);
	if (file_ptr)
	{
		file_ptr -> addDataCount(1);
	}
	else
	{
		dnode<File>* add_node = new dnode<File>(File(file));
		if (files_head)
		{	
			dnode<File>* traverse = files_head;
			while (traverse) //find first node with alph greater string than file
			{
				if (file.compare(traverse -> getData().getFile()) < 0)
				{
					dnode<File>* prev_node = traverse -> getPrev(); //add add_node to dll
					traverse -> setPrev(add_node);
					add_node -> setNext(traverse);
					if (prev_node) //if previous ptr exists, connect to add_node
					{
						prev_node -> setNext(add_node);
						add_node -> setPrev(prev_node);
					}
					else //if prev = NULL, then traverse is head, so add_node is new head
					{
						files_head = add_node;
					}
					return; //quit out if found
				}
				traverse = traverse -> getNext();
			}	
			files_tail -> setNext(add_node); //if all other nodes were less than add_node, add_node is tail
			add_node -> setPrev(files_tail);
			files_tail = add_node;
		}
		else
		{
			files_head = add_node;
			files_tail = add_node;
		}
	}
	addCount(1);
}

dnode<File>* Word::hasFile(std::string name) //return the pointer of a node with this file, or NULL if none exists
{
	dnode<File>* traverse = files_head;
	while (traverse)
	{
		if (name.compare(traverse ->getData().getFile()) == 0 )
		{

			return traverse;
		}
		traverse = traverse -> getNext();
	}
	return traverse;
}

std::string Word::print_word()
{
	std::string output = word + "\n";

	dnode<File>* traverse = files_head;
	while (traverse)
	{	
		File temp_file = traverse -> getData();
		output += temp_file.getFile() + "\nCount " + std::to_string(temp_file.getCount()) + "\n";
		traverse = traverse -> getNext();
	}

 	return output;
}

void Word::print_files_thresh(int thresh) //print all files where count >= thresh
{
	dnode<File>* traverse = files_head;
	while (traverse)
	{
		if (traverse -> getData().getCount() >= thresh)
		{
			std::cout << traverse -> getData().getFile() << std::endl;
		}
		traverse = traverse -> getNext();
	}
}

dnode<File>* Word::getHead()
{
	return files_head;
}
