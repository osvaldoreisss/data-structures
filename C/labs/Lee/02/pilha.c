#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int TOP;
int STACK;

// Function that creates a new stack
void createStack(int n)
{
	STACK = malloc(n * sizeof(int));
	TOP = 0;
}

// Function that returns if a stack is empty
int isEmpty()
{
	return !TOP;
}

// Function that add an item to the stack
void instack(int data)
{
	
	STACK[(*TOP)++] = data;
}


// Function that removes an item from the stack
int unstack()
{
	if (!isEmpty(*top))
	{
		return STACK[--(*top)];
	}
	else
	{
		return -1;
	}
}

