#include <iostream>
#include <string>
#include "BST.h"
#include "AVL.h"
#include "BinaryMinHeap.h"

using namespace std;

void main()
{
	AVL avl1;
	BinaryMinHeap numbers;
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
	avl1.show(avl1.root);
	cout << endl << endl;

	cout << "HEAPS" << endl;
	cout << "=========================" << endl;
	numbers.Insert(Node(12));
	numbers.Insert(Node(23));
	numbers.Insert(Node(5));
	numbers.Insert(Node(8));
	numbers.Insert(Node(10));
	numbers.Insert(Node(21));
	numbers.Insert(Node(11));
	numbers.Insert(Node(17));
	numbers.showHeap();
	Node* topNumber = numbers.ExtractMin();
	if (topNumber != NULL)
	{
		cout << "Root number is " << topNumber->number << endl;
	}
	else
	{
		cout << "Heap must be empty." << endl;
	}
}