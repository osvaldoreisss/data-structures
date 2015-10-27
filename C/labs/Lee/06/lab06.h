#ifndef LAB06_H
#define LAB06_H 1

#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *left, *right;
} Node;

Node* createTree();

Node* createLeaf(int k);

void insert(Node *tree, int k);

Node* search(Node *tree, int k);

Node* removeNode(Node *tree, int k, Node *original_tree);

Node *findParent(Node *tree, Node *k);

Node* findMinNode(Node *tree);

void inorder(Node *tree);

void preorder(Node *tree);

Node *rightRotate(Node *x);
 
Node *leftRotate(Node *x);

Node *splay(Node *root, int key);

Node *searchSplay(Node *root, int key);

#endif
