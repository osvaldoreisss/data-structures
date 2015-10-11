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
    Node *tree = createTree();
    insert(tree, 20);
    insert(tree, 10);
    insert(tree, 9);
    insert(tree, 15);
    insert(tree, 14);
    insert(tree, 16);

    inorder(tree);
    printf("\n");
    Node *ten = search(tree, 10);
    int data = ten->data;
    printf("Ten is %d\n", data);
    return 0;
}
