#ifndef PILHA_H
#define PILHA_H 1

//Function that creates a new stack
int *createStack(int size);

//Function that returns if a stack is empty
int isEmpty(int top);

//Function that add an item to the stack
void instack(int* stack, int data, int* topo);

//Function that removes an item from the stack
int unstack(int* stack, int* topo);

// Function that returns the item at the top of the stack
int top(int *stack, int top);

#endif