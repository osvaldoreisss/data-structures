#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int preIndex;

// Function that creates a new tree
Node *createTree(char info)
{
    Node *r = malloc(sizeof(Node));
    r->data = info;
    r->left = NULL;
    r->right = NULL;
    return r;
}

// Function that frees the memory used by a tree
void destroy(Node *p)
{
  if (p)
  {
    destroy(p->left);
    destroy(p->right);
    free(p);
  }
}

// Function that builds a tree given their preorder and iNoderder traversals
Node *build(char *in, char *pre, int inStart, int inEnd)
{
    // If the start is bigger than the end, return NULL
    if(inStart > inEnd)
        return NULL;

    // Allocating the new node with the next item of the preOrder
    Node *temp = createTree(pre[preIndex++]);
    
    // If start is the end, return the temp
    if(inStart == inEnd)
        return temp;

    // If not, we'll search for the data inside the inOrder traversal
    int inIndex = search(in, inStart, inEnd, temp->data);

    // Using the index of the inorder, we'll recursively build the left and right
    // subtrees
    temp->left = build(in, pre, inStart, inIndex-1);
    temp->right = build(in, pre, inIndex+1, inEnd);
    
    return temp;
}

// Function that searches for a value inside an array
int search(char arr[], int strt, int end, char value)
{
    int i;
    for(i = strt; i <= end; i++)
    {
        if(arr[i] == value)
        return i;
    }
    
    return -1;
}

void printPostorder(Node *Node)
{
    if (Node == NULL)
        return;

    // Visit the left        
    printPostorder(Node->left);
    
    // Visit the right
    printPostorder(Node->right);
    
    // Print the root
    printf("%c", Node->data);
}
