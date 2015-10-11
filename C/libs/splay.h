#ifndef SPLAY_H
#define SPLAY_H 1

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

void removeNode(Node *tree, int k);

Node *findParent(Node *tree, Node *k);

void inorder(Node *tree);
#endif
