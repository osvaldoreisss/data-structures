#include <stdio.h>
#include "matrioshka.h"

int main()
{
	int n, i, size;

	do
	{
		// Getting the number of toys
		scanf("%d", &n);

		// If N = 0, stop
		if (n == 0)
		{
			break;
		}

		// Create a new matrioshka
		newMatrioshka(n);

		// Reading all the toys
		for (i = 0; i < n; i++)
		{
			// Scanning the current size
			scanf("%d ", &size);
		    addMatrioshka(size);
        }

        // We print a message according to the status
        if (isMatrioshka()) printf("Eh Matrioshka.\n"); else printf("Nao eh Matrioshka.\n");

	}
	while (n != 0);

	return 0;
}

