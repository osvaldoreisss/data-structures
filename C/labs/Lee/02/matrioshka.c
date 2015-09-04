#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "matrioshka.h"

int *ARMAZENAMENTO;
int *MATRIOSHKA;
int TOP = -1;
int TOPAR = -1;

void newMatrioshka()
{
	TOP = -1;
    TOPAR = -1;
    ARMAZENAMENTO = createStack();
	MATRIOSHKA = createStack();
}


int addMatrioshka(int size)
{
    
	// If we are trying to close a toy that is not on the top, we fail.
	if (size > 0)
	{
		if (MATRIOSHKA[TOP] + size != 0)
		{
			printf("Matrioshka falhou por fechar algo não no topo (t = %d, top = %d)ao adicionar %d\n", MATRIOSHKA[TOP], TOP, size);
			printf("status:");
			int i;
			for (i = 0; i <= TOP; i++)
			{
				printf("%d ", MATRIOSHKA[i]);
			}
			printf("\n");
			return 0;
		}
		else
		{
			int oldTop = unstack(MATRIOSHKA, &TOP);
			unstack(ARMAZENAMENTO, &TOPAR);
			printf("Unstacked %d. Top is now at %d\n", oldTop, TOP);
			ARMAZENAMENTO[TOPAR] += abs(size);

			if (TOP != -1 && ARMAZENAMENTO[TOPAR] >= abs(MATRIOSHKA[TOP]))
			{
				printf("Matrioshka falhou por estouro ao adicionar %d \t já armazenado = %d \t topo = %d \n", size, ARMAZENAMENTO[TOPAR], MATRIOSHKA[TOP]);
				printf("Status: ");
				int i;
				for (i = 0; i <= TOP; i++)
				{
					printf("%d ", MATRIOSHKA[i]);
				}
				printf("\n");
				printf("Tamanhos: ");
				for (i = 0; i <= TOPAR; i++)
				{
					printf("%d ", ARMAZENAMENTO[i]);
				}
				printf("\n");
				return 0;
			}
			else
			{
				printf("Status: ");
				int i;
				for (i = 0; i <= TOP; i++)
				{
					printf("%d ", MATRIOSHKA[i]);
				}
				printf("\n\n");
				return 1;
			}
		}
	}
	else
	{
		printf("Stacking %d\n", size);
		instack(MATRIOSHKA, size, &TOP);
		printf("After stack, top = %d\n", TOP);
		instack(ARMAZENAMENTO, 0, &TOPAR);
		printf("Status: ");
		int i;
		for (i = 0; i <= TOP; i++)
		{
			printf("%d ", MATRIOSHKA[i]);
		}
		printf("\n\n");
		return 1;
	}

}

