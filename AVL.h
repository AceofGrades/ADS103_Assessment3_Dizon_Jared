#pragma once
#include "BST.h"
// AVL is self balancing binary search tree
class AVL :
    public BST
{
public:
    bool displayRotations = true;

    // Works out height of subtree
    int height(Node* node);

    // Difference between left and right sub trees
    int difference(Node* node);

    // ROTATIONS
    // return: new parent of subtree
    // paramter: current parent of subtree
    // right branch, right child
    Node* RRrotation(Node* parent);
    // left branch, left child
    Node* LLrotation(Node* parent);
    // left branch, right child
    Node* LRrotation(Node* parent);
    // right branch, left child
    Node* RLrotation(Node* parent);

    // BALANCE
    // balances tree structure where parent is middle top node
    // returns new parent after balancing(rotations)
    Node* balance(Node* parent);

    // INSERT
    // recursive insert, considers parent as subtree
    // insert also balances itself
    // returns new root node of tree
    Node* insertAVL(Node* parent, Node* newNumber);

    // overriding insert from parent
    void insert(Node* newNumber);
};