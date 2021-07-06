#pragma once
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


