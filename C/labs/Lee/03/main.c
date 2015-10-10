/* Nome: Felipe Videira Rodrigues
 * RA: 155335
 * Laboratorio 03 - Sistema Único de Saúde */
#include <stdlib.h>
#include <stdio.h>

// Definition of an emergency queue
typedef struct EmergencyQueue
{
	int data; // The data that the node holds
	struct EmergencyQueue *next; // The pointer to the next node
	struct EmergencyQueue *last; // A pointer to the end of the queue - this is only valid for the head
} EQueue; 

// Global variable for the queue
EQueue *queue;

// Function that initializes the queue
void initializeQueue();

// Function that puts the given data to the end of the queue
void enqueue(int data);

// Function that returns the next item on the queue
int dequeue();

// Function that returns a pointer to the node that holds the given data
EQueue *find(int data);

// Function that returns a pointer to the parent node of the one that holds the given data
EQueue *findPointsTo(int data);

// Function that moves a node to the top of the queue, given its data
void moveToFront(int data);

int main()
{
	int n, i, e; // variables for the number of patients, an iterator and the ID of an emergency
	char c = '\0'; // variable for the commands

	// Getting the number of patients
	scanf("%d", &n);

	// Initializing the queue
	initializeQueue();

	// Enqueing all of the patients
	for (i = 1; i <= n; i++)
	{
		enqueue(i);
	}

	// Scanning the commands
	while (c != 'F')
	{
		scanf("%c", &c);

		switch(c)
		{
			case 'A':
				printf("%d ", dequeue());
				break;

			case 'E':
				scanf("%d ", &e);
				moveToFront(e);
				break;
		}
	}
	
	return 0;
}

void initializeQueue()
{
	// Initializing the queue with empty fields
	queue = malloc(sizeof(EQueue));
	queue->data = 0;
	queue->next = NULL;
	queue->last = NULL;
}

void enqueue(int data)
{
	EQueue *last = queue->last; // Pointer for the last item

	// Creating the new item and setting its fields
	EQueue *temp = malloc(sizeof(EQueue));
	temp->data = data;
	temp->next = NULL;

	// If we do have a last node
	if(last)
	{
		// The last node's next node will be the new one
		last->next = temp;
	}
	else
	{
		// If not, the queue's next node will be the new
		queue->next = temp;
	}

	// By any case, the queue's last node will be the new one
	queue->last = temp;
}

int dequeue()
{
	// If the queue is not empty
	if (queue->next)
	{
		// We get the top of the queue
		EQueue *top = queue->next;

		// Store its data
		int data = top->data;

		// Removes it from the front of the queue
		queue->next = top->next;

		// Put it in the end
		enqueue(top->data);

		// Free the memory
		free(top);

		// Return the data it holds
		return data;
	}

	// If the queue is empty, we return -1
	return -1;
}

EQueue *find(int data)
{
	EQueue *aux;

	// One liner that finds a node or returns null if not found
	for(aux = queue; aux && aux->data != data; aux = aux->next);

	return aux;
}

EQueue *findPointsTo(int data)
{
	EQueue *aux;

	// One liner that finds a node's parent or returns null if not found
	for(aux = queue; aux && aux->next->data != data; aux = aux->next);

	return aux;
}

void moveToFront(int data)
{
	EQueue *aux = find(data); // We find the node we want
	EQueue *auxParent = findPointsTo(data); // We find the node that points to the one we want
	EQueue *top = queue->next; // We find the current top

	// If we do have a node with the given data and if it is not the current top
	if (aux && auxParent != queue)
	{
		// The new top will be the one we want
		queue->next = aux;

		// Its parent will now point to whatever the old one pointed to
		auxParent->next = aux->next;

		// And the top will now be the next one after the one we want
		aux->next = top;
	}

	// If the node we got was the last node, its parent will now be the last.
	if (aux == queue->last) queue->last = auxParent;
}