#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "matrioshka.h"

int *ARMAZENAMENTO;
int *MATRIOSHKA;
int TOP = 0;
int TOPAR = 0;
int WAS_EMPTY = 0;

void newMatrioshka(int size)
{
	TOP = 0;
    TOPAR = 0;
    WAS_EMPTY = 0;
    ARMAZENAMENTO = createStack(size);
	MATRIOSHKA = createStack(size);
}


int addMatrioshka(int size)
{
	if(WAS_EMPTY) return 0;
    
	// If we are trying to close a toy that is not on the top, we fail.
	if (size > 0)
	{
		if (top(MATRIOSHKA, TOP) + size != 0)
		{
			//printf("Matrioshka falhou por fechar algo não no topo (t = %d, top = %d)ao adicionar %d\n", top(MATRIOSHKA, TOP), TOP, size);
			//printf("status:");
			int i;
			for (i = 0; i < TOP; i++)
			{
				//printf("%d ", MATRIOSHKA[i]);
			}
			//printf("\n");
			return 0;
		}
		else
		{
			int oldTop = unstack(MATRIOSHKA, &TOP);
			WAS_EMPTY = isEmpty(TOP);
			unstack(ARMAZENAMENTO, &TOPAR);
			//printf("Unstacked %d. Top is now at %d\n", oldTop, TOP);
			ARMAZENAMENTO[TOPAR - 1] += abs(size);

			if (TOP != 0 && top(ARMAZENAMENTO, TOPAR) >= abs(top(MATRIOSHKA, TOP)))
			{
				//printf("Matrioshka falhou por estouro ao adicionar %d \t já armazenado = %d \t topo = %d \n", size, top(ARMAZENAMENTO, TOPAR), top(MATRIOSHKA, TOP));
				//printf("Status: ");
				int i;
				for (i = 0; i < TOP; i++)
				{
					//printf("%d ", MATRIOSHKA[i]);
				}
				//printf("\n");
				//printf("Tamanhos: ");
				for (i = 0; i < TOPAR; i++)
				{
					//printf("%d ", ARMAZENAMENTO[i]);
				}
				//printf("\n");
				return 0;
			}
			else
			{
				//printf("Status: ");
				int i;
				for (i = 0; i < TOP; i++)
				{
					//printf("%d ", MATRIOSHKA[i]);
				}
				//printf("\n\n");
				return 1;
			}
		}
	}
	else
	{
		//printf("Stacking %d\n", size);
		instack(MATRIOSHKA, size, &TOP);
		//printf("After stack, top = %d\n", TOP);
		instack(ARMAZENAMENTO, 0, &TOPAR);
		//printf("Status: ");
		int i;
		for (i = 0; i < TOP; i++)
		{
			//printf("%d ", MATRIOSHKA[i]);
		}
		//printf("\n\n");
		return 1;
	}

}

