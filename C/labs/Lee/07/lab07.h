#ifndef LAB07_H
#define LAB07_H 1

struct node
{
	int left;
	int right;
};
typedef struct node node;

void create_heap(int size);
void insert_item(int data);
void print_heap();
int get_min();
int get_max();
void swap(int *x, int *y);


#endif