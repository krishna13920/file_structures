#ifndef _HEAP_SORT
#define _HEAP_SORT
template <class itemtype>
class SortProject
{	static const int CAPACITY=8;
	itemtype data[CAPACITY];
	
	public:
	SortProject();
	void heapifyUP();
    void heapifyDown();
    void current_heap_push(itemtype input);
    itemtype current_heap_pop();
    int getLeftChildIndex(int parentIndex);// { return 2 * parentIndex+1; }
    int getRightChildIndex(int parentIndex); //{ return 2 * parentIndex+2; }
    int getParentIndex(int childIndex); //{ return (childIndex-1)/2; }
    bool hasLeftChild(int index);// { return getLeftChildIndex(index) <size; }
        bool hasRightChild(int index); //{ return getRightChildIndex(index) <size; }
        bool hasParent(int index); //{ return getParentIndex(index) >=0; }
        itemtype leftChild(int index);// { return data[ getLeftChildIndex(index)]; }
        itemtype rightChild(int index); //{ return data[ getRightChildIndex(index)]; }
        itemtype parent(int index); //{ return data[ getParentIndex(index)]; }
        void swap (int indexOne,int indexTwo);
        int size;
};
//#include "sort.cpp"
#endif



#include<iostream>
#include "sort.h"
using namespace std;
int main()
{
  int size=0;  
  SortProject <int> obj1;
  int array[4]={6,5,7,2};
  int i;
  for(int i=0;i<4;i++)
  {
     obj1.current_heap_push(array[i]);
  }
  for(int j=0;j<4;j++)
  {
  	 cout<<obj1.current_heap_pop()<<endl;
  }
  return 0;
}

template <class itemtype>
SortProject<itemtype>::SortProject()
{
	size=0;
}

template <class itemtype>
void SortProject<itemtype>::heapifyUP()
{
	int index=size-1;
	while(hasParent(index) && parent(index) > data[index])
	{
		swap (getParentIndex(index), index);
		index= getParentIndex(index);
	}
}
template <class itemtype>
void SortProject<itemtype>::heapifyDown()
{
	int index=0;
	while(hasLeftChild(index))
	{
		int smallChildIndex=getLeftChildIndex(index);
		if(hasRightChild(index) && rightChild(index)< leftChild(index))
		{
			smallChildIndex= getRightChildIndex(index);
		}
		if(data[index]< data[smallChildIndex])
		{
			break;
		}
		else 
		{
			swap (index,smallChildIndex);
		}
	}
}

template <class itemtype>
void SortProject<itemtype>::current_heap_push(itemtype input)
{
    size++;
	data[size-1]=input;
    heapifyUP();
    
}

template <class itemtype>
itemtype SortProject<itemtype>::current_heap_pop()
{
	if(size==0) return -1;
    itemtype num=data[0];
    data[0]=data[size-1];
    size--;
    heapifyDown();
    return num;
		
	
}

template <class itemtype>
int SortProject<itemtype>::getLeftChildIndex(int parentIndex)
{
	return 2 * parentIndex+1;
}

template <class itemtype>
int SortProject<itemtype>::getRightChildIndex(int parentIndex)
{
	return 2 * parentIndex+2;
}

template <class itemtype>
int SortProject<itemtype>::getParentIndex(int childIndex)
{
	return (childIndex-1)/2;
}

template <class itemtype>
bool SortProject<itemtype>::hasLeftChild(int index)
{
	return getLeftChildIndex(index) <size;
}

template <class itemtype>
bool SortProject<itemtype>:: hasRightChild(int index)
{
	return getRightChildIndex(index) <size;
}

template <class itemtype>
bool SortProject<itemtype>::hasParent(int index)
{
	return getParentIndex(index) >=0; 
}

template <class itemtype>
itemtype SortProject<itemtype>:: leftChild(int index)
{
	return data[ getLeftChildIndex(index)]; 
}

template <class itemtype>
itemtype SortProject<itemtype>:: rightChild(int index)
{
	return data[ getRightChildIndex(index)];
}

template <class itemtype>
itemtype SortProject<itemtype>:: parent(int index)
{
	return data[ getParentIndex(index)]; 
}

template <class itemtype>
void SortProject<itemtype>::swap (int indexOne,int indexTwo)
{
	itemtype temp= data[indexOne];
	data [indexOne] =data [indexTwo];
	data[indexTwo]=temp;
}
