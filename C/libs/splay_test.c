/*
 * =====================================================================================
 *
 *       Filename:  splay_test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10-10-2015 18:14:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "splay.h"

int main()
{
    // Initializing a new tree
    Node *tree = createTree();

    // Inserting data
    insert(tree, 20);
    insert(tree, 10);
    insert(tree, 9);
    insert(tree, 15);
    insert(tree, 14);
    insert(tree, 16);

    // Traversing in order
    inorder(tree);
    printf("\n");

    // Searching for a node
    Node* ten = search(tree, 10);

    // Evaluating the search
    printf("Searched for a node with value 10 and found one with value = %d\n", ten->data);

    Node *min = findMinNode(tree);
    printf("The minimun key in the tree is %d\n", min->data);
    // Removing a node from the middle of the tree
    tree = removeNode(tree, 15);

    // Traversing the tree again
    inorder(tree);
    printf("\n");

    tree = removeNode(tree, 20);
    inorder(tree);
    printf("\n");
    
    return 0;
}
