#include "BinaryMinHeap.h"

int BinaryMinHeap::leftChildIndex(int parent)
{
    int leftIndex = 2 * parent + 1;
    if (leftIndex < heap.size())
    {
        return leftIndex;
    }
    else
    {
        return -1;
    }
}

int BinaryMinHeap::rightChildIndex(int parent)
{
    int rightIndex = 2 * parent + 2;
    if (rightIndex < heap.size())
    {
        return rightIndex;
    }
    else
    {
        return -1;
    }
}

int BinaryMinHeap::parentIndex(int child)
{
    int parent = (child - 1) / 2;
    if (child == 0)
    {
        return -1;
    }
    else
    {
        return parent;
    }
}

// After inserting, we heapifyup from where that new inserted number ended up
// Compares current node to parent and swaps the smaller to the top
// recursive function, each swap means we call heapifyup on the next higher level
// where we swapped a value
void BinaryMinHeap::heapifyup(int index)
{
    // If index is not the root (top of tree)
    // AND parent index within heap bounds (not negative)
    // AND current node's number is less than parent node's number
    if (index >= 0 && parentIndex(index) >= 0 && heap[index].number < heap[parentIndex(index)].number)
    {
        // If so, swap values between current and parent node
        Node temp = heap[index];
        heap[index] = heap[parentIndex(index)];
        heap[parentIndex(index)] = temp;
        // since we swapped, run heapifyup again recursively on the parent from here
        heapifyup(parentIndex(index));
    }
}

// Down is less efficient because we compare both children first before going down
// Usually called when destroyed root of tree
// Recursive function, keeps calling itself as it swaps down tree
void BinaryMinHeap::heapifydown(int index)
{
    // Get left and right indexes
    int childL = leftChildIndex(index);
    int childR = rightChildIndex(index);
    // Child variable representing path we'll compare down
    int childIndex = childL;
    // If ChildL is NOT -1 AND ChildR is NOT -1
    // AND right child's number is less than left's
    if (childL >= 0 && childR >= 0 && heap[childR].number < heap[childL].number)
    {
        // Make right child index the focus
        childIndex = childR;
    }

    // If the childIndex is not the troot node AND is not -1
    // AND current node's bigger than child node's
    if (childIndex > 0 && heap[index].number > heap[childIndex].number)
    {
        // We should swap current with child, because we want smaller ones closer to the top
        Node temp = heap[index];
        heap[index] = heap[childIndex];
        heap[childIndex] = temp;
        // Recurse further down
        heapifydown(childIndex);
    }
}

// Inserts at the lowest next free spot in tree (keeps things balanced)
void BinaryMinHeap::Insert(Node element)
{
    heap.push_back(element);
    heapifyup(heap.size() - 1);
}

void BinaryMinHeap::DeleteMin()
{
    // Can't delete if heap is empty
    if (heap.size() == 0)
    {
        cout << "Heap empty..." << endl;
        return;
    }
    // Copy value in last element into root
    heap[0] = heap[heap.size() - 1]; // heap.at(heap.size()-1);
    // Delete last element
    heap.pop_back();
    // Then heapifydown starting from root(index 0)
    heapifydown(0);
    cout << "Root number deleted" << endl;
}

// Get root number node from heap tree structure (or first element in vector)
Node* BinaryMinHeap::ExtractMin()
{
    if (heap.size() == 0)
    {
        return NULL;
    }
    else
    {
        // return &(heap.front());
        Node* n = &(heap.front()); // get memory address of number at front of array / heap
        return n;
    }
}

void BinaryMinHeap::showHeap()
{
    cout << "Heap-->";
    for (Node n : heap)
    {
        cout << "[" << n.number << "]" << endl;
    }
    cout << endl;
}

int BinaryMinHeap::Size()
{
    return heap.size();
}
