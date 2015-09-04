#include <stdio.h>
#include "matrioshka.h"

int main()
{
	int n, i, info;

	do
	{
		//leitura do numero de dados que serao recebidos
		scanf("%d", &n);

		//se n = 0, parar 
		if (n == 0)
		{
			break;
		}

		newMatrioshka();
        int result = 1;
		//loop que le todos os n brinquedos da sequencia
		for (i = 0; i < n; i++)
		{
			scanf("%d ", &info);
            if(result)
            {
			    result = addMatrioshka(info);
            }
        }
        if (result) printf("Eh Matrioshka.\n"); else printf("Nao eh Matrioshka.\n");

	}
	while (n != 0);


	return 0;
}

