#ifndef DNODE_H
#define DNODE_H
#include <iostream>
#include <cstddef>
//Sean Shanley, 3/7/2020
template <class T>
class dnode
{
	private:
		dnode<T>* prev;
		T data;
		dnode<T>* next;

	public:
		/*
		dnode();
		dnode(T item);

		dnode<T>* getPrev();
		T getData();
		T* getDataPtr();
		dnode<T>* getNext();

		void setPrev(dnode<T>* ptr);
		void setData(T val);
		void addDataCount(int x);
		void setNext(dnode<T>* ptr);	
		*/
		dnode()
	        {
	                 next = NULL;
	                 prev = NULL;
	         }

                 dnode(T item)
	         {
	                 prev = NULL;
	                 data = item;
	                 next = NULL;
	         }

	         dnode<T>* getPrev()
	         {
	                 return prev;
	         }

	         T getData()
	         {
		         return data;
	         }

	         T* getDataPtr() //get a pointer to the data
	         {
	                 return &data;
		 }

		 dnode<T>* getNext()
		 {
		         return next;
		 }
	
		 void setPrev(dnode<T>* ptr)
	         {
	                prev = ptr;
	         }

	         void setData(T value)
	         {
	                data = value;
	         }
	
	 	 void setNext(dnode<T>* ptr)
	         {
		        next = ptr;
		 }
     		
	         void addDataCount(int x) //edit the count of the data
	         {
	               data.addCount(x);
	         }
};

#endif
