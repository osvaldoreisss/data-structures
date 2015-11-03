#include <stdio.h>
#include <stdlib.h>
#include "lab07.h"

node* heap;
int max_size;
int current_size;

void create_heap(int size)
{
	int n = size / 2 + size % 2 + 1;
	max_size = size;
	heap = (node*) malloc(n * sizeof(node));
	current_size = 0;
}

void insert_item(int data)
{
    if (current_size == max_size) return ;
	// current_size < 2 is a special case
	if (current_size < 2)
	{
		if(current_size == 1)
		{
			if(data < heap[1].left)
			{
				heap[1].left = data;
			}
			else
			{
				heap[1].right = data;
			}
		}
		else // current size is 0
		{
			heap[1].left = data;
			heap[1].right = data;
		}
		current_size++;
		return ;
	}
	// Current size >= 2
	int lastNode = current_size / 2 + current_size % 2;
	int minHeap = 0;

	if (current_size % 2)
		// Odd number
		if (data < heap[lastNode].left)
			// X will be the left end
			minHeap = 1;
		else
			minHeap = 0;
	else
	{
		lastNode++;
		if (data <= heap[lastNode / 2].left)
			minHeap = 1;
		else
			minHeap = 0;
	}

	if (minHeap)
	{
		int i = lastNode;
		while (i != 1 && data < heap[i / 2].left)
		{
			heap[i].left = heap[i / 2].left;
			i /= 2;
		}

		heap[i].left = data;
		current_size++;
		if (current_size % 2)
			heap[lastNode].right = heap[lastNode].left;
	}
	else
	{
		int i = lastNode;
		while (i != 1 && data > heap[i / 2].right)
		{
			heap[i].right = heap[i / 2].right;
			i /= 2;
		}
		heap[i].right = data;
		current_size++;
		if (current_size % 2)
			heap[lastNode].left = heap[lastNode].right;
	}
	return ;

}

void swap(int *x, int *y)
{
	int temp;
	temp = *y;
	x = y;
	*y = temp;
}

void print_heap_min()
{
	int i;
	for (i = 1; i < current_size / 2 + current_size % 2; i++)
	{
	    printf("%d ", heap[i].left);
	}
	printf("\n");
}

void print_heap_max()
{
	int i;
	for (i = 1; i < current_size / 2 + current_size % 2; i++)
	{
	    printf("%d ", heap[i].right);
	}
	printf("\n");
}

int get_min()
{
	int data;
	if (current_size == 0) return ;
	data = heap[1].left;

	int lastNode = current_size / 2 + current_size % 2;
	int y;

	if (current_size % 2)
	{
		y = heap[lastNode].left;
		lastNode--;
	}
	else
	{
		y = heap[lastNode].right;
		heap[lastNode].right = heap[lastNode].left;
	}
	current_size--;
	int i = 1;
	int ci = 2;

	while (ci <= lastNode)
	{
		if (ci < lastNode && heap[ci].left > heap[ci+1].left) ci++;
		if (y <= heap[ci].left) break;
		heap[i].left = heap[ci].left;
		if (y > heap[ci].right) swap(&y, &heap[ci].right);
		i = ci;
		ci *= 2;
	}
	if (i == lastNode && current_size % 2)
		heap[lastNode].left = heap[lastNode].right;
	else
		heap[i].left = y;

	return data;
}

int get_max()
{
	if (current_size == 0) return ;

	int data = heap[1].right;
	int lastNode = current_size / 2 + current_size % 2;
	int y;

	if (current_size % 2)
	{
	    y = heap[lastNode].left;
		lastNode--;
	}
	else
	{
		y = heap[lastNode].right;
		heap[lastNode].right = heap[lastNode].left;
	}
	current_size--;

	int i = 1;
	int ci = 2;

	while (ci <= lastNode)
	{
	    if (ci < lastNode && heap[ci].right < heap[ci + 1].right) ci++;
		if (y >= heap[ci].right) break;

		heap[i].right = heap[ci].right;
		if (y < heap[ci].left) swap(&y, &heap[ci].left);
		i = ci;
		ci *= 2;
	}
	heap[i].right = y;

	return data;
}
