#pragma once

/*
This is the basic node class.
The class stores data and a link to right and left children.

Again, pay no attention to the LLNode, that was when I was going to do a different project.

*/
template <class T>
struct Node {
	T _data;
};

template <class T>
struct LLNode : Node<T> {
	LLNode* _next;
};

template <class T>
struct BSTNode : Node<T> {
public:
	BSTNode* _right;
	BSTNode* _left;
};


