#ifndef TREE_H
#define TREE_H 1
typedef struct Node
{
  char data;
  struct Node *left, *right;
} Node;

int preIndex;

Node *createTree(char info);

void destroy(Node *p);

Node *build(char *in, char *pre, int inStart, int inEnd);

int search(char arr[], int strt, int end, char value);

void printPostorder(Node *node);

#endif

