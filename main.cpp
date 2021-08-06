#include <iostream>
#include <string>
#include "BST.h"
#include "AVL.h"

using namespace std;

void main()
{
	AVL avl1;
	avl1.displayRotations = true;
	cout << "Initial numbers" << endl;
	cout << "======================" << endl;
	avl1.insert(new Node(12));
	avl1.insert(new Node(23));
	avl1.insert(new Node(5));
	avl1.insert(new Node(8));
	avl1.insert(new Node(10));
	avl1.insert(new Node(21));
	avl1.insert(new Node(11));
	avl1.insert(new Node(17));
	cout << endl << endl;
	cout << "AVL level order traversal" << endl;
	cout << "=========================" << endl;
	avl1.levelOrderTraversal(avl1.root);
}