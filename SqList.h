#include <iostream>
#define MaxSize 50 
#define NULL 0 //define empty pointer to be 0
typedef char ElemType;

class SqList
{
	ElemType * data; //pointer for data
	int length; //length of the list
public:
	SqList(); //constructor
	bool isEmpty(); //to tell whether the list is empty
	int getLength(); //get length of the list
	void dispList(); //show the list
	bool getElement(int index, ElemType &e); //get element at the index given
	int locateElement(ElemType e); //locate element in the list
	bool insertElement(int index, ElemType e); //insert element at given index
	bool deleteElement(int index, ElemType &e); //delete element at given index
virtual ~SqList(); 
};
