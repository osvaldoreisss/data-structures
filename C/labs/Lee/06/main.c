#include <stdlib.h>
#include <stdio.h>
#include "lab06.h"

int main()
{
	Node *tree = createTree();
	int count, i, temp;

	scanf("%d", &count);

	for (i = 0; i < count; i++)
	{
		scanf("%d", &temp);
		insert(tree, temp);
	}

	char command = '\0';

	while (command != 'f')
	{
		scanf("%c", &command);

		switch(command)
		{
			case 'i':
				scanf("%d", &temp);
				insert(tree, temp);
				tree = splay(tree, temp);
				break;
			case 'b':
				scanf("%d", &temp);
				tree = searchSplay(tree, temp);
				break;
			case 'r':
				scanf("%d", &temp);
				tree = removeNode(tree, temp, tree);
				break;
			case 'f':
				printf("Pre-order :   ");
				preorder(tree);
				printf("\n");
				printf("In-order  :   ");
				inorder(tree);
				printf("\n");
				return 0;
		}

	}

	printf("Pre-order :   ");
	preorder(tree);
	printf("\n");
	printf("In-order  :   ");
	inorder(tree);
	printf("\n");
	return 0;
}