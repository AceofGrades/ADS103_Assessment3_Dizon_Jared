#pragma once
#include "Node.h"

// Binary Search Tree
// Root node acting as sort of center
// Everything smaller than root, stored on left branch
// Everything else, to the right

class BST
{
public:
	Node* root = NULL;
	virtual void insert(Node* newNumber);
	Node* search(int number, bool showSearchPath = false);

	void inOrderTraversal(Node* current);
	void preOrderTraversal(Node* current);
	void postOrderTraversal(Node* current);
	void levelOrderTraversal(Node *root);
};

