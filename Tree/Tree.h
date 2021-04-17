#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>
#include <exception>
#include <limits>

class Tree
{
public:
    struct Node
    {
        int value;
        Node *lChild;
        Node *rChild;
        Node(int v, Node *l, Node *r);
        Node(int v);
    };
    Node *root;

public:
    Tree();
    // Other Tree methods.

    virtual void levelOrderBinaryTree(int arr[], int size);

    virtual Node *levelOrderBinaryTree(int arr[], int start, int size);

    virtual void insert(int value);

private:
    Node *insert(int value, Node *node);

public:
    virtual void printPreOrder();

private:
    void printPreOrder(Node *node); // pre order

public:
    virtual void nthPreOrder(int index);

private:
    void nthPreOrder(Node *node, int index, int& counter); // pre order

public:
    virtual void printPostOrder();

private:
    void printPostOrder(Node *node); // post order

public:
    virtual void nthPostOrder(int index);

private:
    void nthPostOrder(Node *node, int index, int& counter); // post order

public:
    virtual void printInOrder();

private:
    void printInOrder(Node *node); // In order

public:
    virtual void nthInOrder(int index);

private:
    void nthInOrder(Node *node, int index, int& counter);

public:
    virtual void printBredthFirst();

    virtual void printDepthFirst();

    virtual bool find(int value);

    virtual bool find2(int value);

    virtual int findMin();

    virtual int findMax();

    virtual Node *findMax(Node *curr);

    virtual Node *findMin(Node *curr);

    virtual void free();

    virtual void freeTree(Node* node);

    virtual void remove(int value);

private:
    Node *remove(Node *node, int value);

public:
    virtual int treeDepth();

private:
    int treeDepth(Node *root);

public:
    virtual bool isEqual(Tree *T2);

private:
    bool isEqual(Node *node1, Node *node2);

public:
    virtual Node *ancestor(int first, int second);

private:
    Node *ancestor(Node *curr, int first, int second);

public:
    virtual Tree *copyTree();

private:
    Node *copyTree(Node *curr);

public:
    virtual Tree *copyMirrorTree();

private:
    Node *copyMirrorTree(Node *curr);

public:
    virtual int numNodes();

    virtual int numNodes(Node *curr);

    virtual int numFullNodesBT();

    virtual int numFullNodesBT(Node *curr);

    virtual int maxLengthPathBT();

private:
    int maxLengthPathBT(Node *curr); // diameter

public:
    virtual int numLeafNodes();

private:
    int numLeafNodes(Node *curr);

public:
    virtual int sumAllBT();

private:
    int sumAllBT(Node *curr);

public:
    virtual void iterativePreOrder();

    virtual void iterativePostOrder();

    virtual void iterativeInOrder();

    virtual bool isBST3(Node *root);
    virtual bool isBST3();

    virtual bool isBST();

    virtual bool isBST(Node *curr, int min, int max);

public:
    virtual bool isBST2();

    virtual bool isBST2(Node *root, int &count); // in order traversal

    virtual Node *treeToListRec();

public:
    Node *treeToListRec(Node *curr);
    void  printDLL(Node *root);

public:
    virtual void printAllPath();


private:
    void printAllPath(Node *curr, std::vector<int>& stk);

public:
    virtual int lca(int first, int second);

private:
    Node *lca(Node *curr, int first, int second);

public:
    virtual int lcaBST(int first, int second);

    virtual int lcaBST(Node *curr, int first, int second);

    virtual void trimOutsideRange(int min, int max);

    virtual Node *trimOutsideRange(Node *curr, int min, int max);

    virtual void printInRange(int min, int max);

private:
    void printInRange(Node *root, int min, int max);

public:
    virtual int floorBST(int val);

    virtual int ceilBST(int val);

    virtual int findMaxBT();

private:
    int findMaxBT(Node *curr);

public:
    virtual bool searchBT(Node *root, int value);
    bool searchBT(int value);
    virtual void createBinarySearchTree(int arr[], int size);

    virtual Node *createBinarySearchTree(int arr[], int start, int end);

    virtual void printLevelOrderLineByLine();
    virtual void printLevelOrderLineByLine2();
    virtual void printSpiralTree();
    bool isCompleteTree();
    bool isCompleteTreeUtil(Node* curr, int index, int count);
    bool isCompleteTree2();
    bool isHeapUtil(Node* curr, int parentValue);
    bool isHeap();
    bool isHeapUtil2(Node* curr, int index, int count, int parentValue);
    bool isHeap2();


};
