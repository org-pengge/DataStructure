#include "SqList.h"

SqList::SqList()
{
	data = new ElemType[MaxSize];
	length = 0; //initializing
}

bool SqList::isEmpty()
{
	return (length == 0);
}

int SqList::getLength()
{
	return length;
}

void SqList::dispList()
{
	for (int i = 0; i < length; i++)
	{
		if (i % 10 == 0 && i > 0) //10 elements each line
		{
			std::cout << std::endl;
		}
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

bool SqList::getElement(int index, ElemType & e)
{
	if (index < 1 || length < index)
	{
		std::cout << "Error: Index out of bounds. Cannot get the element at index " 
			<< index << "." << std::endl;
		return false;
	}
	e = data[index - 1]; //transfer to logical index
	return true;
}

int SqList::locateElement(ElemType e)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == e) //if ElemType is a user-define data structure, then it should overload operator '=='
		{
			return (i + 1);
		}
	}
	return 0; //can not locate the element, return 0
}

bool SqList::insertElement(int index, ElemType e)
{
	if (index < 1 || index > length + 1)
	{
		std::cout << "Error: Index out of bounds. Cannot insert element at index "
			<< index << std::endl;
		return false;
	}
	if ((length + 1) % MaxSize == 0) //the list is full, so need to enlarge it
	{
		ElemType * tmp = new ElemType[length + MaxSize]; //create a new list that has a total length of old-list-length + MaxSize
		for (int j = 0; j < length; j++)
		{
			tmp[j] = data[j]; //copy the list
		}
		delete[] data; //destory old list
		data = tmp; //list pointer point to new list
	}
	int i;
	index--; //transfer to logical index
	for (i = length; i > index; i--)
	{
		data[i] = data[i - 1]; 
	}
	data[i] = e;
	length++; //length add 1
	return true;
}

bool SqList::deleteElement(int index, ElemType & e)
{
	if (index < 1 || index > length)
	{
		std::cout << "Error: Index out of bounds. Cannot delete element at index "
			<< index << std::endl;
		return false;
	}
	index--; //transfer to logical index
	e = data[index];
	for (int i = index; i < length - 1; i++)
	{
		data[i] = data[i + 1];
	}
	length--; //length minus 1
	return true;
}


SqList::~SqList() //release memory of data
{
	delete[] data;
	data = NULL;
}
