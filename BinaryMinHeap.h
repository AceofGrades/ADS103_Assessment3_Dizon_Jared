#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include "Node.h"
#include "BST.h"

using namespace std;

class BinaryMinHeap:
	public BST
{
public:
	vector<Node> heap;
	int leftChildIndex(int parent);
	int rightChildIndex(int parent);
	int parentIndex(int child);

	void heapifyup(int index);
	void heapifydown(int index);

	void Insert(Node element);
	void DeleteMin();
	Node* ExtractMin();
	void showHeap();
	int Size();

};

