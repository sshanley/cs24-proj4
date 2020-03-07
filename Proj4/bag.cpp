#include <iostream>
#include <string>
#include "bag.h"

//Sean Shanley 3/7/2020

Bag::~Bag()
{
        dnode<Word>* traverse = container;
        while (traverse)
        {
                if (traverse -> getPrev()) //delete previous node if it exists
                {
			traverse -> getPrev() -> getData().clear();
                        delete traverse -> getPrev();
                }

                if (traverse -> getNext()) //if next exists, move there, else delte yourself
                {
                        traverse = traverse -> getNext();
                }
                else
                {
			traverse -> getData().clear();
                        delete traverse;
			traverse = NULL;
                }
        }

}


void Bag::print_words(std::string name)
{
	std::string output = "";
	dnode<Word>* traverse = container;
	while (traverse)
	{
		output += traverse -> getData().print_word() + "\n";
		traverse = traverse -> getNext();
	}
	std::cout<<output;
}

dnode<Word>* Bag::has_word(std::string name)
{
	dnode<Word>* traverse = container;
	while (traverse)
	{
		if (name.compare(traverse -> getData().getWord()) == 0)
		{
			return traverse;
		}
		traverse = traverse -> getNext();
	}
	return traverse;
}

void Bag::insert_word(std::string phrase, std::string file)
{
	dnode<Word>* word_exists = has_word(phrase);
	if (word_exists)
	{
		//check if file exists
		//
		//if so, add 1 to file
		//
		//else, add a new file
		// which would just be...
		word_exists -> getDataPtr() -> addFile(file);
	}
	else //may have to actually sort later btw
	{
		dnode<Word>* new_word = new dnode<Word>();
		new_word -> setData(Word(phrase));
		new_word -> getDataPtr() -> addFile(file);
		if (container)
		{
			dnode<Word>* traverse = container;
                        while (traverse) //find first node with alph greater string than phrase
                        {
                                if (phrase.compare(traverse -> getData().getWord()) < 0)
                                {
                                       dnode<Word>* prev_node = traverse -> getPrev(); //add node to dll
	                               traverse -> setPrev(new_word);
	                               new_word -> setNext(traverse);
                                       if (prev_node) //if previous ptr exists, connect to node
                                       {
                                              prev_node -> setNext(new_word);
		                              new_word -> setPrev(prev_node);
                                       }
                                       else //if prev = NULL, then traverse is head, so node is new head
                                       {
                                              container = new_word;
				       }
			              return; //quit out if found
		                  }
                               traverse = traverse -> getNext();
                        }
			tail -> setNext(new_word);
			new_word -> setPrev(tail);
			tail = new_word;
		}
		else
		{
			container = new_word;
			tail = new_word;
		}
	}
}

void Bag::searchcount(std::string phrase, int thresh)
{
	dnode<Word>* word_exists = has_word(phrase);
	if (!word_exists)
	{
		return;
	}
	word_exists -> getData().print_files_thresh(thresh);
}

void Bag::searchunion(std::string word1, std::string word2)
{
	dnode<Word>* w1 = has_word(word1);
	dnode<Word>* w2 = has_word(word2);
	if(!w1 && !w2) //if neither word exists, return nothing
	{
		return;
	}
	//get the two heads if they exist
	dnode<File>* head1 = NULL;//default values
	dnode<File>* head2 = NULL;
	if (w1)
	{
		head1 = w1 -> getData().getHead();
	}
	if (w2)
	{
		head2 = w2 -> getData().getHead();
	}

	std::string f1;
	std::string f2;
	//choose the file name that is lower alph wise, and print it
	//while both point to valid values
	while (head1 && head2)
	{
		f1 = head1 -> getData().getFile();
		f2 = head2 -> getData().getFile();

		if (f1.compare(f2)<0)
		{
			std::cout<<f1<<std::endl;
			head1 = head1 -> getNext();
		}
		else
		{
			std::cout<<f2<<std::endl;
			head2 = head2 -> getNext();
			if (f1.compare(f2) == 0)
			{
				head1 = head1 -> getNext();
			}
		}
	}
	//after 1 head no longer points to data, you can print the rest of the files in the other head
	dnode<File>* last_head;
	if (head1)
	{
		last_head = head1;
	}
	else
	{
		last_head = head2;
	}
	while (last_head)
	{
		std::cout<<last_head -> getData().getFile()<<std::endl;
		last_head = last_head -> getNext();
	}

	return;

}
