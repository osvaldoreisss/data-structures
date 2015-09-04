#ifndef PILHA_H
#define PILHA_H 1

// Function that creates a new stack
void createStack(int n);

// Function that returns if a stack is empty
int isEmpty();

// Function that add an item to the stack
void instack(int* stack, int data, int* topo);

// Function that removes an item from the stack
int unstack(int* stack, int* topo);

#endif