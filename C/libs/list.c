/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  Implementation of a generic linked list
 *
 *        Version:  1.0
 *        Created:  03-09-2015 10:24:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Felipe Rodrigues (FBidu)
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "list.h"

 // Function that initializes an empty list
Node *newList()
{
	Node* temp = malloc(sizeof(Node));
	temp->data = 0;
	temp->next = NULL;

	return temp;
}

// Function that returns a pointer to the end of a list
Node *lastNode(Node *list)
{
	Node *temp;

	for (temp = list; temp->next; temp = temp->next);

	return temp;
}

// Function that returns a pointer to the first node of data = key
Node *findData(Node *list, int key)
{
	Node *temp;

	for (temp = list; temp && temp->data != key; temp = temp->next);

	return temp;
}

// Function that returns a pointer to the node the points to node a
Node *findPointsTo(Node *list, Node *a)
{
	Node *temp;

	for (temp = list; temp && temp->next != a; temp = temp->next);

	return temp;
}

// Function that removes from the list the node a
void removeNode(Node *list, Node *a)
{
	Node* points_to_a = findPointsTo(list, a);
	Node* pointed_by_a = a->next;

	points_to_a->next = pointed_by_a;

	free(a);
}

// Function that prints a list
void printList(Node *list)
{
	if (list)
	{
		printf("%d ", list->data);
		printList(list->next);
	}
	else
	{
		printf("\n");
	}
}

// Function that inserts a new node before the node a with data = k
void insertAfter(Node *list, Node *a, int k)
{
	Node *temp = malloc(sizeof(Node));

	temp->data = k;
	temp->next = a->next;

	a->next = temp;
}

// Function that inserts a new node at the end of the list
void insertAtEnd(Node *list, int k)
{
	Node *last = lastNode(list);

	Node *temp = malloc(sizeof(Node));

	temp->next = NULL;
	temp->data = k;

	last->next = temp;
}