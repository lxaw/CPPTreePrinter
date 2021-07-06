#pragma once
#include "Node.h"

#include <string>

template <class T>
class BinarySearchTree
{
public:
	void add(T aData);

	// process, left, right
	// pass by left
	void printPreorder();

	void printTree(bool printDepth);

	// see if data in the bst 
	bool search(T aData);

	// remove an element
	void remove(T aData);

private:
	int _maxDepth = 0;
	BSTNode<T>* _root = nullptr;
	BSTNode<T>* newBSTNode(T aData);

	// print if the tree is empty
	void printEmptyTree();

	// recursive methods
	BSTNode<T>* add(BSTNode<T>* aBSTNode, T aData);
	void printPreorder(BSTNode<T>* aBSTNode);
	bool search(BSTNode<T>* aBSTNode, T aData);
	BSTNode<T>* remove(BSTNode<T>* aBSTNode, T aData);
	BSTNode<T>* findMinInTree(BSTNode<T>* aBSTNode);
	void printTree(BSTNode<T>* aBSTNode, std::string prefix,BSTNode<T>* leftChild, BSTNode<T>* rightChild,int currLevel,bool printDepth);
};

