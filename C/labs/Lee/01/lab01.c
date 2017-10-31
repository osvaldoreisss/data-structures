/* Nome: Felipe Videira Rodrigues
* RA: 150556
* Laboratorio 01 - O problema do acesso à lista */

/*Colaboração de osvaldoreisss

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} Node;

// Function that prints a list starting at the first passed node
void print_list(Node* list);

// Function that returns a pointer to a node inside a list where data = key
Node* find(Node* list, int key);

// Function that swaps two nodes inside a list, given their pointers
void swap_nodes (Node* list, Node* a, Node* b);

// Function that swaps two nodes inside a list, given their data
void swap_by_data(Node* list, int a, int b);

// Function that inserts a new node at the end of a list and returns the cost
int insert_at_end(Node* list, int data);

// Function that moves a node to the front of a list
void move_to_front(Node* list, Node* a);

// Function that access an item using the "Move To Front" strategy and returns its cost
int access_mtf(Node* list, int data);

// Function that transposes (swaps) the node A with the node that comes before it.
void transpose(Node* list, Node* a);

// Function that access an item using the "Transpose" strategy and returns its cost
int access_tr(Node* list, int data);

// Function that removes a node and return the cost of the operation
int remove_node(Node* list, int data);

int main()
{
	Node* list_mtf = malloc(sizeof(Node));
	Node* list_tr = malloc(sizeof(Node));

	list_mtf->next = NULL;
	list_tr->next = NULL;

	int n, r, i, k;
	int cost_tr = 0;
	int cost_mtf = 0;

	scanf("%d", &n);
	scanf("%d", &r);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &k);

		insert_at_end(list_mtf, k);
		insert_at_end(list_tr, k);
	}


	for (i = 0; i < r ; i++)
	{
		char c;

		scanf(" %c %d", &c, &k);

		switch(c)
		{
			case 'a':
				cost_mtf += access_mtf(list_mtf, k);
				cost_tr += access_tr(list_tr, k);
				break;

			case 'i':
				cost_mtf += insert_at_end(list_mtf, k);
				cost_tr += insert_at_end(list_tr, k);
				access_tr(list_tr, k);
				break;

			case 'r':
				cost_mtf += remove_node(list_mtf, k);
				cost_tr += remove_node(list_tr, k);
				break;
		}

	}

	printf("%d\n", cost_mtf);
	print_list(list_mtf->next);

	printf("%d\n", cost_tr);
	print_list(list_tr->next);

	return 0;
}

void print_list(Node* list)
{
	// Do we have a list?
	if(list)
	{
		// Yes, print the current data
		printf("%d ", list->data);

		// Recursively print the next item
		print_list(list->next);
	}
	else
	{
		// No, just print a new line
		printf("\n");
	}
}

void swap_nodes (Node* list, Node* a, Node* b)
{
	Node* points_to_a;
	Node* points_to_b;
	Node* pointed_by_b;

	// Finding the node that points to a
	for (points_to_a = list;
		points_to_a && points_to_a->next != a;
		points_to_a = points_to_a->next);

	// Finding the node that points to b
	for (points_to_b = list;
		points_to_b && points_to_b->next != b;
		points_to_b = points_to_b->next);

	// Making whatever pointed to a, point to b
	points_to_a->next = b;

	// Whatever pointed to B, now points to a
	points_to_b->next = a;

	// Assigning the node pointed by b to the proper variable
	pointed_by_b = b->next;

	// B points to whatever A pointed to
	b->next = a->next;

	// A points to whatever B pointed to
	a->next = pointed_by_b;
}

int insert_at_end(Node* list, int data)
{
	int cost = 0;

	// Where is the end of the list?
	Node* insert_at;

	// Finding the note that has a next = null;
	for (insert_at = list; insert_at->next; insert_at = insert_at->next, cost++);

	// Allocating the space
	Node* new = malloc(sizeof(Node));

	// Assigning the data
	new->data = data;

	// Makes it the 'new end';
	new->next = NULL;

	// Makes the former end points to the new one
	insert_at->next = new;

	cost++;

	return cost;

}

Node* find(Node* list, int key)
{
	// The default case is NULL - there is no node with data = key
	Node* i = NULL;

	// While we have a node and its data is != k, we keep looking
	for (i = list; i && i->data != key; i = i->next);

	// We then return whatever i is. 
	// Given that we loop until 'i' exists, it will be NULL if nothing is found
	return i;
}

void swap_by_data(Node* list, int a, int b)
{
	// Finding a pointer to the node with data = a
	Node* node_a = find(list, a);

	// Finding a pointer to the node with data = b
	Node* node_b = find(list, b);

	// If they exist, we swap them
	if (node_a && node_b) swap_nodes(list, node_a, node_b);
}

void move_to_front(Node* list, Node* a)
{
	Node* head = list;
	Node* front = list->next;
	Node* points_to_a;

	// Finding the node that points to a
	for (points_to_a = list;
		points_to_a && points_to_a->next != a;
		points_to_a = points_to_a->next);

	// Whatever pointed to a, now points to what a pointed to
	points_to_a->next = a->next;

	// A points to the front node
	a->next = front;

	// The head points to A;
	head->next = a;
}

int access_mtf(Node* list, int data)
{
	Node *key;
	int cost = 0;

	for(key = list; key && key->data != data; key = key->next, cost++);

	if(key && key != list->next) move_to_front(list, key);

	return cost;
}

void transpose(Node* list, Node* a)
{
	Node* points_to_a;

	// Finding the node that points to a
	for (points_to_a = list;
		points_to_a && points_to_a->next != a;
		points_to_a = points_to_a->next);

	swap_nodes(list, points_to_a, a);
}

int access_tr(Node* list, int data)
{
	Node *key;

	int cost = 0;

	for(key = list; key && key->data != data; key = key->next, cost++);

	if(key && key != list->next) transpose(list, key);

	return cost;
}

int remove_node(Node* list, int data)
{
	Node *key;
	int cost = 0;

	for(key = list; key && key->data != data; key = key->next, cost++);

	if(key)
	{
		Node* points_to_key;

		// Finding the node that points to a
		for (points_to_key = list;
			points_to_key && points_to_key->next != key;
			points_to_key = points_to_key->next);

		points_to_key->next = key->next;

		free(key);
	}

	return cost;
}
