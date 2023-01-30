/*
 * SLLSet.cpp
 *
 *  Created on: Nov. 17, 2021
 *      Author: moham
 */


#include "SLLSet.h"
#include <iostream>

SLLSet::SLLSet() // construct empty SSLSet object
{
	size = 0;
	head = NULL;
}
SLLSet::SLLSet(int sortedArray[], int arrSize) // construct SSLSet object containing integers from input array
{
	// empty array
	if (arrSize == 0){
		size = 0;
		head = NULL;
	}
	else{
		// traverse array, move newNode to next element
		size = arrSize;
		SLLNode* newNode = new SLLNode(sortedArray[0], NULL);
		head = newNode;
		for (int i = 1; i < size; i++){
			newNode->next =  new SLLNode(sortedArray[i], NULL);
			newNode = newNode->next;
		}
	}
}

int SLLSet::getSize() // get size of set
{
	int size = 0;
	    SLLNode* readerHead = head;
	    // increment size until end of list is reached
	    while (readerHead){
	        size++;
	        readerHead = readerHead->next;
	    }
	    return size;
}

SLLSet SLLSet::copy() // return deep copy of current SLLSet
{
	// new array and head
	int *copylist = new int[size], i = 0;
	SLLNode* copyHead = head;

	// traverse until end of linked list
	while(copyHead){
		// place values into new list and move head
		copylist[i++] = copyHead->value;
		copyHead = copyHead->next;
	}
	SLLSet* copy = (new SLLSet(copylist, size));
	//copy->size = size;
	delete[] copylist;
	return *copy;
}

bool SLLSet::isIn(int v) // return if input value is in SLLSet
{
    SLLNode* node = head;
    while (node){
    	if (node->value == v)   {return true;}  // in SLLSet
    	node = node->next;
    }
    return false;
}

void SLLSet::add(int v)
{
	SLLNode *readerHead = head, *newNode = new SLLNode();
	newNode->value = v;
	// add in v to list if it is not already in list (no duplicates in set), else do nothing
	if (!isIn(v)){
		// empty set or v is smaller than value in set
	   if(!(readerHead) || (v < readerHead->value))
	   {
		   newNode->next = head;
		   head = newNode;
	   }
	   else{
		while (readerHead->next){
			if (v <= readerHead->next->value)
			{
				// move readerHead
			    newNode->next  = readerHead->next;
			    readerHead->next = newNode;
			    return;
			}
			else readerHead = readerHead->next; // move readerHead
		}
		// set as newNode at tail
		readerHead->next = newNode;
	   }
	}
}

void SLLSet::remove(int v) // removes v from the current SLLSet if v was an element of
// the SLLSet. It does nothing otherwise.
{
   SLLNode *readerHead = head;
   
   if (isIn(v)){
	   size--;
	   // if head and parameter match then move head
	   if (readerHead->value == v){
		   SLLNode* newHead = readerHead->next;
		   delete head;
		   head = newHead;
	   }
	   else{
		   //as long as it is not last or second last element
		   while (readerHead && readerHead->next){
			   // if next value and parameter are same, move next value
			   if (readerHead->next->value == v){
				   SLLNode* temp = readerHead->next;
				   readerHead->next = readerHead->next->next;
				   delete temp;
			   }
			   // move readerHead
			   readerHead = readerHead->next;
		   }
	   }
   }
}

SLLSet SLLSet::setUnion(SLLSet s)
/*returns a new SLLSet which represents the union of
the current (this) SLLSet and the input SLLSet s */
{
	SLLSet unionset = s.copy();
	SLLNode *readerHead = head;

	while (readerHead){
		unionset.add(readerHead->value);
		readerHead = readerHead->next;
	}
	return unionset;
}

SLLSet SLLSet::intersection(SLLSet s)
{
/* returns a new SLLSet which represents the inter-
section of this SLLSet and the input SLLSet s*/
	SLLSet  inter = SLLSet();
	SLLNode* readerHead = head;
	while (readerHead){
		if (s.isIn(readerHead->value)){
			inter.add(readerHead->value);
		}
		readerHead = readerHead->next;
	}
	return inter;
}

SLLSet SLLSet::difference(SLLSet s)
/* returns a new SLLSet which represents the difference
between this SLLSet and the input SLLSet s */
{
	SLLSet diff = copy();
	SLLSet remove = intersection(s);   // remove all common elements -> obtain elements from intersection()
	SLLNode *readerHead = remove.head; // track head of what we want to remove

	 //remove all same elements from diff
	while (readerHead) {
		diff.remove(readerHead->value);
		readerHead=readerHead->next;
	}
	return diff;
}

SLLSet SLLSet::setUnion(SLLSet sArray[],int size)
/* returns a new object rep-
resenting the union of the sets in the array */
{
	SLLSet union_obj = SLLSet();
	for (int i = 0; i < size; ++i) {
		union_obj = union_obj.setUnion(sArray[i]);
	}
	return union_obj;
}

string SLLSet::toString() // return string representation of set
{
	string output = "";
	SLLNode* readerHead = head;
	// append value followed by comma until end of set
	while(readerHead){
		output += to_string(readerHead->value);
		readerHead = readerHead->next;

		if(readerHead){
			output += ", ";
		}
	}
   return output;
}


