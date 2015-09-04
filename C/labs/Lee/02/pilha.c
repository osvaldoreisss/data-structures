#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

//Function that creates a new stack
int* createStack()
{
	return malloc(sizeof(int));
}

//Function that returns if a stack is empty
int isEmpty(int top)
{
	return top == -1;
}

//Function that add an item to the stack
void instack(int* stack, int data, int* top)
{
	(*top)++;
	stack[(*top)] = data;
}


//Function that removes an item from the stack
int unstack(int* stack, int* top)
{
	if (!isEmpty(*top))
	{
		int item = stack[(*top)];
		(*top)--;
		return item;
	}
	else
	{
		return -1;
	}
}

