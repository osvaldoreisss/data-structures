#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

//Function that creates a new stack
int* newStack(int size)
{
	return malloc(size * sizeof(int));
}

//Function that returns if a stack is empty
int isEmpty(int top)
{
	return !top;
}

//Function that add an item to the stack
void instack(int* stack, int data, int* top)
{
	stack[(*top)] = data;
	(*top)++;
}


//Function that removes an item from the stack
int unstack(int* stack, int* top)
{
	if (!isEmpty(*top))
	{
		(*top)--;
		int item = stack[(*top)];
		return item;
	}
	else
	{
		return -1;
	}
}

// Function that reads the top of the stack
int top(int *stack, int top)
{
	return stack[top - 1];
}