/* Nome: Felipe Videira Rodrigues
* RA: 155335
* Laboratorio 05 - Pré, In e Pós */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    int count = 0;
    int size = 0;
    int i;
    
    scanf("%d", &count);
    
    for(i = 0; i < count; i++)
    {
        scanf("%d ", &size);
        preIndex = 0;
        char *in, *pre;
        in = malloc(size*sizeof(char));
        pre = malloc(size*sizeof(char));
        scanf("%s %s", pre, in);

        Node *root = malloc(sizeof(Node));
        root = build(in, pre, 0, size - 1);
        
        printf("Teste %d: ", i);
        printPostorder(root);
        printf("\n");
    }
    
    return 0;
}

