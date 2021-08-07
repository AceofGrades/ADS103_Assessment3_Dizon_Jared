#include "BST.h"
#include <queue>

void BST::insert(Node* newNumber)
{
    // if root = NULL (empty), make newNumber the root
    if (root == NULL)
    {
        root = newNumber;
        return;
        // exit function early
    }

    //pointers to help navigate tree
    Node* current = root; // current node we're pointing at
    Node* parent = NULL; // Parent of current (node visited last time)

    while (true) // infinite loop
    {
        // Keep track of where we were before moving on
        parent = current;
        // Left or right?
        // If newNumber number is less than current, move to left
        if (newNumber->number < current->number)
        {
            // < means we go down to the left side of tree
            current = current->leftChild;
            // If current = NULL, we found empty space to insert new number
            if (current == NULL)
            {
                // Done, new number is stuck here
                parent->leftChild = newNumber;
                return; // finished
            }
        }
        else
        {
            // go down right path
            current = current->rightChild;
            // If current is NULL, insert there
            if (current == NULL)
            {
                parent->rightChild = newNumber;
                return;
            }
        }
    }
}

Node* BST::search(int number, bool showSearchPath)
{
    // If tree empty, can't find student matching number
    if (root == NULL)
    {
        return NULL;
    }

    Node* current = root;

    // keep looping until found
    while (current->number != number)
    {
        // If current is NULL, search number cannot be found
        if (current == NULL)
        {
            return NULL;
        }

        if (showSearchPath)
        {
            cout << current->number << endl;
        }

        // Haven't found it yet, let's explore where number should go in the tree path
        if (number < current->number)
        {
            // GO left
            current = current->leftChild;
        }
        else
        {
            // go right
            current = current->rightChild;
        }
    }

    return current; // should be pointing to match in tree
}

//outputs stuff in the tree in ascending order :D
void BST::inOrderTraversal(Node* current)
{
    //current == null is end of this branch path, this if
    //stops from infinite looping
    if (current != NULL)
    {
        inOrderTraversal(current->leftChild);
        cout << current->number << endl;
        inOrderTraversal(current->rightChild);
    }
}

void BST::preOrderTraversal(Node* current)
{
    if (current != NULL)
    {
        cout << current->number << endl;
        preOrderTraversal(current->leftChild);
        preOrderTraversal(current->rightChild);
    }
}

void BST::postOrderTraversal(Node* current)
{
    if (current != NULL)
    {
        postOrderTraversal(current->leftChild);
        postOrderTraversal(current->rightChild);
        cout << current->number << endl;
    }
}

// Referenced here: https://www.geeksforgeeks.org/level-order-tree-traversal/
void BST::show(Node* p)
{
    // Base case
    if (root == NULL)
    {
        return;
    }

    // Create empty queue for level order traversal
    queue<LevelNode> q;

    // Enqueue root and initialise height
    q.push(LevelNode(root, 0));
    int previousOutputLevel = -1;

    while (q.empty() == false)
    {
        // Print front of queue and remove from queue
        LevelNode node = q.front();
        if (node.level != previousOutputLevel)
        {
            cout << endl;
            cout << node.level << ": ";
            previousOutputLevel = node.level;
        }
        cout << node.node->number<<" ";
        q.pop();

        // Enqueue left child
        if (node.node->leftChild != NULL)
        {
            q.push(LevelNode(node.node->leftChild, node.level + 1));
        }

        // Enqueue right child
        if (node.node->rightChild != NULL)
        {
            q.push(LevelNode(node.node->rightChild, node.level + 1));
        }
    }
}
