#include <stdio.h>
#include <iostream>

#include "MyArrayList.h"
#include "Node.h"

/*

This class has nothing to do with the video. 
I was going to do a different project prior, and wanted to make an array list that can merge sort.

*/

template <class T>
MyArrayList<T>::MyArrayList() {
	_head = nullptr;
	_tail = nullptr;
}

template <class T>
T MyArrayList<T>::at(int index) {
	// returns the value at the index;
	T ret = 0;
	if (_size > index) {
		// find the value
		LLNode<T>* temp = _head;
		if (index == 0) {
			return temp->_data;
		}
		else if (index == -1) {
			if (_tail != nullptr) {
				return _tail->_data;
			}
			else {
				std::cout << "Index error on empty list. Return 0.\n";
			}
		}
		else {
			for (int i = 0;i < index && temp->_next != nullptr;i++) {
				temp = temp->_next;
			}
			return temp->_data;
		}
	}
	else {
		// invalid index
		std::cout << "Index out of bounds. Return 0.\n";
	}

	return ret;
}
template <class T>
T MyArrayList<T>::popTail() {
	/*
	BE CAREFUL WITH POINTERS!
	DELETE THEN SEND TO NULL, not other way around!
	FIX TAIL!
	*/
	T ret;
	if (_head == nullptr) {
		//		std::cout << "EMPTY" << "\n";
				// empty list
				// just make it return zeros
		ret = 0;
	}
	else if (_head->_next == nullptr) {
		// one item in list
		std::cout << "ONE ITEM" << "\n";
		ret = _head->_data;
		delete _head;
		_head = nullptr;
		_tail = nullptr;

		_size--;
	}
	else {
		// more than 1 element is present
		// get to second to last node in list
		std::cout << "MORE THAN 1 ITEM" << "\n";
		LLNode<T>* temp = _head;
		while (temp->_next->_next != nullptr) {
			temp = temp->_next;
		}
		// temp now is the second to last item
		ret = temp->_next->_data;
		delete temp->_next;
		temp->_next = nullptr;

		// update tail
		_tail = temp;

		_size--;
	}
	// decrement size
	return ret;
}

template <class T>
void MyArrayList<T>::add(T aData) {
	//	std::cout << "ADD" << "\n";
	if (_head == nullptr) {
		// empty list, just add to head
//			std::cout << "EMPTY LIST" << "\n";
		_head = new LLNode<T>;
		_head->_data = aData;
		_head->_next = nullptr;
		_tail = _head;


	}
	else {
		LLNode<T>* temp = _head;
		LLNode<T>* newLLNode = new LLNode<T>;

		newLLNode->_data = aData;
		newLLNode->_next = nullptr;

		// already have elements
		while (temp) {
			if (temp->_next == nullptr) {
				temp->_next = newLLNode;

				_tail = newLLNode;
				break;
			}
			temp = temp->_next;
		}
	}
	//		std::cout << "TAIL DATA: " << _tail->_data << "\n";
	_size++;
}

/* ************** MERGE SORT LINKED LIST ************** */
template <class T>
LLNode<T>* getMiddleElement(LLNode<T>* aHead) {
	if (aHead == nullptr) {
		// return the head val if head null
		return aHead;
	}
	// create two refs for the ll
	// slow ref
	LLNode<T>* slow = aHead;
	// fast ref
	LLNode<T>* fast = aHead;
	// iterature using fast
	while (fast->_next != nullptr && fast->_next->_next != nullptr) {
		// update slow
		slow = slow->_next;
		// update fast
		fast = fast->_next->_next;
	}
	// return slow ref that is has the middle element of the ll
	return slow;
}

template <class T>
LLNode<T>* sortedMerge(LLNode<T>* lLLNode, LLNode<T>* rLLNode) {
	// sorts the two halves of ll
	if (lLLNode == nullptr) {
		return rLLNode;
	}
	if (rLLNode == nullptr) {
		return lLLNode;
	}
	// temp ref to refer to sorted ll
	LLNode<T>* temp = nullptr;
	// check if lLLNode data smaller than rLLNode
	if (lLLNode->_data <= rLLNode->_data) {
		// update temp
		temp = lLLNode;
		// recurse on lLLNode->_next
		temp->_next = sortedMerge(lLLNode->_next, rLLNode);
	}
	else {
		// update temp
		temp = rLLNode;
		// recurse on rLLNode->_next
		temp->_next = sortedMerge(lLLNode, rLLNode->_next);
	}
	// ll sorted, return
	return temp;
}
template <class T>
LLNode<T>* mergeSort(LLNode<T>* head) {
	// performs merge sort on the llinked list
	if (head == nullptr || head->_next == nullptr) {
		return head;
	}
	else {
		// get middle
		LLNode<T>* firstHalf = getMiddleElement(head);
		// make second half of ll
		LLNode<T>* secondHalf = firstHalf->_next;
		// break middle elementref
		firstHalf->_next = nullptr;

		// recurse on two halves
		LLNode<T>* left = mergeSort(head);
		LLNode<T>* right = mergeSort(secondHalf);
		// call for sorting
		LLNode<T>* sortedList = sortedMerge(left, right);
		// return
		return sortedList;
	}
}

template <class T>
void MyArrayList<T>::sort() {
	// update head
	_head = mergeSort(_head);

	// update tail (likely a better way)
	LLNode<T>* temp = _head;
	while (temp->_next != nullptr) {
		temp = temp->_next;
	}
	_tail = temp;
}

/* ************** MERGE SORT LINKED LIST END************** */




template <class T>
void MyArrayList<T>::print() {
	if (_head == nullptr) {
		std::cout << "print(): List is empty." << "\n";
		return;
	}
	else {
		// have elements
		LLNode<T>* temp = _head;
		while (temp) {
			std::cout << temp->_data << " ";
			temp = temp->_next;
		}
		std::cout << "\n";
	}
}


template <class T>
int MyArrayList<T>::getSize() {
	return _size;
}
