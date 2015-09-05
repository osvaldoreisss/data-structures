#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "matrioshka.h"

int *STORAGE; // Stack for keep track of the storage in each toy
int *MATRIOSHKA; // Stack for the toys
int TOP = 0; // Position of the toys's top
int TOP_STORAGE = 0; // Position of the storage's top
int WAS_EMPTY = 0; // Variable that holds wether or not the toy's stack was ever empty
int IS_MATRIOSHKA = 1; // Variable that tells if we do have a valid matrioshka. The default is yes

// Creates a new matrioshka
void newMatrioshka(int size)
{
	// First we reset all of the variables
	TOP = 0;
    TOP_STORAGE = 0;
    WAS_EMPTY = 0;
    IS_MATRIOSHKA = 1;

    // Then we create the stacks
    STORAGE = newStack(size);
	MATRIOSHKA = newStack(size);
}


// Function that add a toy inside the current stack
void addMatrioshka(int size)
{
	// If the current toy is no long a valid matrioshka, nothing will change this so
	// there's no point adding more things
	if (IS_MATRIOSHKA)
	{
		// If the current stack was ever empty, we should fail 
		// because we'd be trying to add something in the nowhere
		if(WAS_EMPTY)
		{
			IS_MATRIOSHKA = 0;
			return;
		}
	    
		// If size > 0, we are 'closing' a toy
		if (size > 0)
		{
			// If we are closing a toy that does not correspond to the one currently open, we should fail.
			if (top(MATRIOSHKA, TOP) + size != 0)
			{
				IS_MATRIOSHKA = 0;
				return;
			}
			else
			{
				// If it does correspond, we should unstack the current toy and do some checkings regarding the storage

				// First we unstack the toy
				unstack(MATRIOSHKA, &TOP);

				// Then we check if the stack is empty
				WAS_EMPTY = isEmpty(TOP);

				// We unstack the storage amount of the removed toy
				unstack(STORAGE, &TOP_STORAGE);

				// Then we increment the now current toy storage by the size of the removed toy
				STORAGE[TOP_STORAGE - 1] += abs(size);

				// If we are not at the last toy we should check if the current toy is holding just as much as it is capable of
				if (TOP != 0 && top(STORAGE, TOP_STORAGE) >= abs(top(MATRIOSHKA, TOP)))
				{
					IS_MATRIOSHKA = 0;
					return;
				}
				else
				{
					// If so, we should go on
					IS_MATRIOSHKA = 1;
					return;
				}
			}
		}

		// If size < 0, we're just adding a new toy
		else
		{
			// We should stack the toy
			instack(MATRIOSHKA, size, &TOP);

			// Stack the storage of the toy
			instack(STORAGE, 0, &TOP_STORAGE);

			// And return true
			IS_MATRIOSHKA = 1;
			return;
		}
	}
}

int isMatrioshka()
{
	return IS_MATRIOSHKA;
}