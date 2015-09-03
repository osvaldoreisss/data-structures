/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description:  Header for a generic linked list implementation
 *
 *        Version:  1.0
 *        Created:  03-09-2015 10:10:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Felipe Rodrigues (FBidu)
 *
 * =====================================================================================
 */

#ifndef LIST_H
#define LIST_H 1

#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

// Function that initializes an empty list
Node *newList();

// Function that returns a pointer to the end of a list
Node *lastNode(Node *list);

// Function that returns a pointer to the first node of data = key
Node *findData(Node *list, int key);

// Function that returns a pointer to the node the points to node a
Node *findPointsTo(Node *list, Node *a);

// Function that removes from the list the node a
void removeNode(Node *list, Node *a);

// Function that prints a list
void printList(Node *list);

// Function that inserts a new node before the node a with data = k
void insertAfter(Node *list, Node *a, int k);

// Function that inserts a new node at the end of the list
void insertAtEnd(Node *list, int k);

#endif
