#include "AVL.h"

// using recursion, we keep exploring down, and pass final height values up
int AVL::height(Node* node)
{
    int h = 0;
    // Helps break recursion cycle when we get to Nulls at bottom of branch
    if (node != NULL)
    {
        int leftH = height(node->leftChild);
        int rightH = height(node->rightChild);

        int maxH = max(leftH, rightH);
        h = maxH + 1;
    }
    else
    {
        return h;
    }
}

int AVL::difference(Node* node)
{
    // if empty tree, balance, 0
    if (node == NULL)
    {
        return 0;
    }

    int leftH = height(node->leftChild);
    int rightH = height(node->rightChild);
    int balanceFactor = leftH - rightH;

    return balanceFactor;
}

Node* AVL::RRrotation(Node* parent)
{
    Node* temp = parent->rightChild;
    parent->rightChild = temp->leftChild;
    temp->leftChild = parent;
    if (displayRotations)
    {
        //cout << "RR rotation on " << parent->number << endl;
    }

    return temp;
}

Node* AVL::LLrotation(Node* parent)
{
    Node* temp = parent->leftChild;
    parent->leftChild = temp->rightChild;
    temp->rightChild = parent;
    if (displayRotations)
    {
        //cout << "LL rotation on " << parent->number << endl;
    }

    return temp;
}

// needs TWO rotations
// first rotation rotates bottom 2 nodes, turns whole structure into RR rotation
// second rtoation uses RR rotation
Node* AVL::LRrotation(Node* parent)
{
    Node* temp = parent->leftChild;
    parent->leftChild = RRrotation(temp);
    if (displayRotations)
    {
        //cout << "LR rotations on " << parent->number << endl;
    }

    return LLrotation(parent);
}

Node* AVL::RLrotation(Node* parent)
{
    Node* temp = parent->rightChild;
    parent->rightChild = LLrotation(temp);
    if (displayRotations)
    {
        //cout << "RL rotations on " << parent->number << endl;
    }

    return RRrotation(parent);
}

Node* AVL::balance(Node* parent)
{
    // get balancefactor
    int balanceFactor = difference(parent);

    //if balancefactor not within -1, 0, 1, work out what rotations to do
    if (balanceFactor > 1)
    {
        // left branch heavy, work out if eft or right is heavy
        if (difference(parent->leftChild) > 0)
        {
            // left child unbalanced
            parent = LLrotation(parent);
        }
        else
        {
            // right child unbalanced
            parent = LRrotation(parent);
        }
    }
    else if (balanceFactor < -1)
    {
        // right branch heavy, but which child
        if (difference(parent->rightChild) > 0)
        {
            // left child heavy
            parent = RLrotation(parent);
        }
        else
        {
            // right child heavy
            parent = RRrotation(parent);
        }
    }

    return parent;
}

Node* AVL::insertAVL(Node* parent, Node* newNumber)
{
    // if sub tree empty, this becomes the parent
    if (parent == NULL)
    {
        parent = newNumber;
        return parent;
    }

    // parent not NULL, so no empty space to put new number in
    // we need to go down either left or right path
    if (newNumber->number < parent->number)
    {
        parent->leftChild = insertAVL(parent->leftChild, newNumber);
        parent = balance(parent);
    }
    else // assume ID is greater than or equal to parent
    {
        parent->rightChild = insertAVL(parent->rightChild, newNumber);
        parent = balance(parent);
    }
}

void AVL::insert(Node* newNumber)
{
    cout << newNumber->number << endl;
    root = insertAVL(root, newNumber);
}
