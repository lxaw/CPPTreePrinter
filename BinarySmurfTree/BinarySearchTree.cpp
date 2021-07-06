#include <stdio.h>
#include <iostream>

#include "BinarySearchTree.h"
#include "Node.h"


/* ***** UTIL METHODS ******/
template <class T>
int compareTo(T dataA, T dataB) {
	if (dataA > dataB) {
		return 1;
	}
	else if (dataA < dataB) {
		return -1;
	}
	else {
		return 0;
	}
}
template<class T>
void BinarySearchTree<T>::printEmptyTree() {
	std::cout << "binary search tree is empty" << "\n";
}
/* ***** UTIL METHODS END ******/


template <class T>
BSTNode<T>* BinarySearchTree<T>::add(BSTNode<T>* aBSTNode, T aData) {
	if (aBSTNode == nullptr) {
		// hit leaf
		aBSTNode = newBSTNode(aData);
	}
	else if (compareTo(aData, aBSTNode->_data) < 0) {
		// aData less than aBSTNode, go left
		aBSTNode->_left = add(aBSTNode->_left, aData);
	}
	else if (compareTo(aData, aBSTNode->_data) > 0) {
		// aData greater than aBSTNode, go right
		aBSTNode->_right = add(aBSTNode->_right, aData);
	}
	else {
		aBSTNode->_left = add(aBSTNode->_left, aData);
	}
	// return all the way up to root
	return aBSTNode;
}

template<class T>
BSTNode<T>* BinarySearchTree<T>::newBSTNode(T aData) {
	BSTNode<T>* temp = new BSTNode<T>;
	temp->_data = aData;
	temp->_left = temp->_right = nullptr;

	return temp;
}

template<class T>
void BinarySearchTree<T>::add(T aData) {
	if (_root == nullptr) {
		_root = newBSTNode(aData);
	}
	else {
		// recursively add the element
		add(_root, aData);
	}
}

template <class T>
void BinarySearchTree<T>::printPreorder(BSTNode<T>* aBSTNode) {
	if (aBSTNode == nullptr) {
		return;
	}
	std::cout << aBSTNode->_data << "\n";
	printPreorder(aBSTNode->_left);
	printPreorder(aBSTNode->_right);
}

template<class T>
void BinarySearchTree<T>::printPreorder() {
	if (_root == nullptr) {
		printEmptyTree();
		return;
	}
	else {
		printPreorder(_root);
	}
}

template <class T>
bool BinarySearchTree<T>::search(BSTNode<T>* aBSTNode, T aData) {
	if (aBSTNode == nullptr) {
		return false;
	}
	else if (compareTo(aData, aBSTNode->_data) > 0) {
		// go right
		search(aBSTNode->_right, aData);
	}
	else if (compareTo(aData, aBSTNode->_data) < 0) {
		// go left
		search(aBSTNode->_left, aData);
	}
	else {
		return true;
	}
}

template <class T>
bool BinarySearchTree<T>::search(T aData) {
	if (_root == nullptr) {
		printEmptyTree();
		return false;
	}
	else if (compareTo(aData, _root->_data) > 0) {
		// go right
		return search(_root->_right, aData);
	}
	else if (compareTo(aData, _root->_data) < 0) {
		// gotta go left
		return search(_root->_left, aData);
	}
	else {
		return true;
	}
}

template <class T>
void BinarySearchTree<T>::remove(T aData) {
	_root = remove(_root, aData);
}

template<class T>
BSTNode<T>* BinarySearchTree<T>::remove(BSTNode<T>* aBSTNode, T aData) {
	// find the node
	if (aBSTNode == nullptr) {
		return nullptr;
	}
	else if (compareTo(aData, aBSTNode->_data) < 0) {
		// a data smaller, go left
		aBSTNode->_left = remove(aBSTNode->_left, aData);
	}
	else if (compareTo(aData, aBSTNode->_data) > 0) {
		// go right
		aBSTNode->_right = remove(aBSTNode->_right, aData);
	}
	else {
		// found it!
		// check how many children node has
		if (aBSTNode->_right == nullptr) {
			// left could exist, or it could be null
			// regardless, return aBSTNode->_left
			return aBSTNode->_left;
		}
		else if (aBSTNode->_left == nullptr) {
			// here we know right child not null
			return aBSTNode->_right;
		}
		// if havent returned so far, means we have two children
		// need to start from right sub tree and find smallest value
		// temp is the node that is smallest val in aBSTNode's right subtree
		BSTNode<T>* temp = findMinInTree(aBSTNode->_right);
		aBSTNode->_data = temp->_data;
		// now we have a dup node, gotta remove the duplicate data
		aBSTNode->_right = remove(aBSTNode->_right, temp->_data);
	}
	// backtrack to parent's node, then reassign child's val
	return aBSTNode;
}

template <class T>
BSTNode<T>* BinarySearchTree<T>::findMinInTree(BSTNode<T>* aBSTNode) {
	if (aBSTNode == nullptr) {
		return nullptr;
	}
	else if (aBSTNode->_left == nullptr) {
		return aBSTNode;
	}
	else {
		return findMinInTree(aBSTNode->_left);
	}
}

template <class T>
void BinarySearchTree<T>::printTree(BSTNode<T>* currNode, std::string prefix, BSTNode<T>* parentLeft, BSTNode<T>* parentRight,int currDepth,bool printDepth) {
	if (currNode == nullptr) {
		return;
	}
	int newDepth = currDepth + 1;
	std::string newPrefix = prefix;
	if (printDepth) {
		if (currNode == _root) {
			std::cout << newPrefix  << currNode->_data << " -- depth: " << newDepth<< "\n";
		}
		else {
			std::cout << newPrefix <<"L_" << currNode->_data << " -- depth: " << newDepth<< "\n";
		}
	}
	else {
		if (currNode == _root) {
			std::cout << newPrefix << currNode->_data << "\n";
		}
		else {
			std::cout << newPrefix<<"L__" << currNode->_data<< "\n";
		}

	}
	BSTNode<T>* left = currNode->_left;
	BSTNode<T>* right = currNode->_right;
	
	if (parentRight && (parentLeft == currNode)) {
		// has two children
		newPrefix.append("|  ");
	}
	else {
		newPrefix.append("   ");
	}

	if (currDepth > _maxDepth) {
		_maxDepth = currDepth;
	}
		
	printTree(left,newPrefix,left,right,newDepth,printDepth);
	printTree(right,newPrefix,left,right,newDepth,printDepth);
}

template <class T>
void BinarySearchTree<T>::printTree(bool printDepth) {
	printTree(_root, "", _root->_left,_root->_right,0,printDepth);
	std::cout << "\n";

	std::cout << "max depth reached: " << _maxDepth << ".";
}





