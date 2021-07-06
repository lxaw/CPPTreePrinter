#include <iostream>
#include <random>

#include "BinarySearchTree.h"
#include "BinarySearchTree.cpp"



int main()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> uni(0, 200);
	BinarySearchTree<int> bst;
	for (int i = 0;i < 50; i++) {
		int rand_int = uni(rng);
		bst.add(rand_int);
	}
	bst.printTree(false);

}
